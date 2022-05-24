﻿using System;
using System.IO;
using System.Collections.Generic;
using System.Text.Json;
using System.Text.Json.Serialization;



namespace CSharpDemo
{
    class Program
    {  
        static List<string> ReadFileToLines(string filepath)
        {
            StreamReader r = new StreamReader(filepath);
            string content = r.ReadToEnd();
            r.Close();
            List<string> lines = new List<string>();
            using (StringReader reader = new StringReader(content))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    lines.Add(line);
                }
            }
            return lines;
        }

        // 从一行读取record
        public static List<string> ReadRecordFromLine(string line)
        {
            List<string> row = new List<string>();
            int pos = 0;
            while (pos < line.Length)
            {
                string field = "";
                pos = ParseNextColumn(line, pos, out field);
                row.Add(field.Trim());
                if (pos < 0)
                {
                    break;
                }
            }
            return row;
        }

        public static int ParseNextColumn(string line, int start, out string field)
        {
            bool in_quote = false;
            if (line[start] == Config.AutogenConfigManager.TABUGEN_CSV_QUOTE)
            {
                in_quote = true;
                start++;
            }
            int pos = start;
            for (; pos < line.Length; pos++)
            {
                if (in_quote && line[pos] == Config.AutogenConfigManager.TABUGEN_CSV_QUOTE)
                {
                    if (pos + 1 < line.Length && line[pos + 1] == Config.AutogenConfigManager.TABUGEN_CSV_SEP)
                    {
                        field = line.Substring(start, pos - start);
                        return pos + 2;
                    }
                    else
                    {
                        field = line.Substring(start, pos - start);
                        return pos + 1;
                    }
                }
                if (!in_quote && line[pos] == Config.AutogenConfigManager.TABUGEN_CSV_SEP)
                {
                    field = line.Substring(start, pos - start);
                    return pos + 1;
                }
            }
            field = line.Substring(start, pos);
            return -1;
        }

        static void TestLoadCSV(string rootPath)
        {
            string filename = "soldier_property_define.csv";
            string filepath = Path.GetFullPath(string.Format("{0}/res/{1}", rootPath, filename));
            Console.WriteLine("load file {0}", filepath);
            var lines = ReadFileToLines(filepath);
            var list = new Config.SoldierPropertyDefine[lines.Count];
            for(int i = 0; i < list.Length; i++)
            {
                var row = ReadRecordFromLine(lines[i]);
                var item = new Config.SoldierPropertyDefine();
                item.ParseFromRow(row);
                list[i] = item;
                Console.WriteLine(JsonSerializer.Serialize<Config.SoldierPropertyDefine>(item));
            }
        }

        static void TestLoadJSON(String rootPath)
        {
            string filename = "soldier_property_define.json";
            string filepath = Path.GetFullPath(string.Format("{0}/res/{1}", rootPath, filename));
            Console.WriteLine("load file {0}", filepath);
            StreamReader reader = new StreamReader(filepath);
            var content = reader.ReadToEnd();
            var conflist = JsonSerializer.Deserialize<Config.SoldierPropertyDefine[]>(content);
            var text = JsonSerializer.Serialize<Config.SoldierPropertyDefine[]>(conflist);
            Console.WriteLine(text);
        }
        
        static void Main(string[] args)
        {
            string rootPath = "..";
            if (args.Length > 1) {
                rootPath = args[1];
            }            
            try
            {
                TestLoadCSV(rootPath);
                Console.WriteLine("-----------------------------------------------");
                TestLoadJSON(rootPath);
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}