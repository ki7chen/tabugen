"""
Copyright (C) 2018-present ichenq@outlook.com. All rights reserved.
Distributed under the terms and conditions of the Apache License.
See accompanying files LICENSE.
"""

import os
from argparse import Namespace
import tabugen.lang as lang
import tabugen.predef as predef
import tabugen.util.helper as helper
import tabugen.util.tableutil as tableutil
import tabugen.version as version
from tabugen.structs import Struct, StructField, ArrayField, EmbedField
from tabugen.generator.go.gen_csv_load import GoCsvLoadGenerator


# Go代码生成器
class GoStructGenerator:
    TAB_SPACE = '\t'

    @staticmethod
    def name():
        return "go"

    def __init__(self):
        self.parse_gen = None
        self.json_snake_case = False

    def enable_gen_parse(self, name):
        if name == 'csv':
            self.parse_gen = GoCsvLoadGenerator()

    # 生成字段定义
    def gen_field_define(self, field: StructField, max_type_len: int, max_name_len: int, json_snake_case: bool,
                         remove_suffix_num: bool, tabs: int) -> str:
        text = ''
        typename = lang.map_go_type(field.origin_type_name)
        assert typename != "", field.origin_type_name
        name = field.camel_case_name
        space = self.TAB_SPACE * tabs
        if remove_suffix_num:
            name = tableutil.remove_field_suffix(name)

        name = helper.pad_spaces(name, max_name_len + 4)
        typename = helper.pad_spaces(typename, max_type_len + 4)
        if json_snake_case:
            tag_name = field.name
            if remove_suffix_num:
                tag_name = tableutil.remove_field_suffix(tag_name)
            tag_name = helper.camel_to_snake(tag_name)
            text += '%s%s %s `json:"%s"`' % (space, name, typename, tag_name)
        else:
            text += '%s%s %s' % (space, name, typename)
        if field.comment:
            text += ' // %s' % field.comment
        text += '\n'
        return text

    def gen_embed_define(self, field: EmbedField, max_type_len: int, max_name_len: int, json_snake_case: bool, tabs: int) -> str:
        name = helper.pad_spaces(field.field_name, max_name_len + 4)
        typename = helper.pad_spaces(field.class_name, max_type_len + 4)
        text = ''
        space = self.TAB_SPACE * tabs
        if json_snake_case:
            tag_name = field.field_name
            tag_name = helper.camel_to_snake(tag_name)
            text += '%s%s %s `json:"%s"`' % (space, name, typename, tag_name)
        else:
            text += '%s%s %s' % (space, name, typename)
        if field.comment:
            text += ' // %s' % field.comment
        text += '\n'
        return text

    # 生成嵌入类型定义
    def gen_embed_type(self, embed: EmbedField, args: Namespace) -> str:
        max_name_len, max_type_len = embed.max_length(lang.map_go_type)
        content = 'type %s struct {\n' % embed.class_name
        for field in embed.element_fields:
            text = self.gen_field_define(field, max_type_len, max_name_len, args.json_snake_case, True, 1)
            content += text
        content += '}\n'

        return content

    def gen_array_type(self, struct: Struct, array: ArrayField) -> str:
        pass

    # 生成struct
    def gen_go_struct(self, struct: Struct, args: Namespace) -> str:
        content = ''

        if struct.comment:
            content += '// %s %s\n' % struct.comment

        for embed in struct.embed_fields:
            content += self.gen_embed_type(embed, args)
            content += '\n'

        content += 'type %s struct {\n' % struct.camel_case_name

        fields = struct.fields
        max_name_len = struct.max_field_name_length()
        max_type_len = struct.max_field_type_length(lang.map_go_type)

        for col, field in enumerate(fields):
            text = self.gen_field_define(field, max_type_len, max_name_len, args.json_snake_case, False, 1)
            content += text
        for array in struct.array_fields:
            content += self.gen_array_type(struct, array)
        for embed in struct.embed_fields:
            text = self.gen_embed_define(embed, max_type_len, max_name_len, args.json_snake_case, 1)
            content += text

        content += '}\n'
        return content

    def generate(self, struct: Struct, args: Namespace) -> str:
        content = ''
        content += self.gen_go_struct(struct, args)
        content += '\n'
        if self.parse_gen is not None:
            content += self.parse_gen.generate(struct)
        return content

    def run(self, descriptors: list[Struct], filepath: str, args: Namespace):
        content = '// This file is auto-generated by Tabugen v%s, DO NOT EDIT!\n\npackage %s\n\n'
        content = content % (version.VER_STRING, args.package)

        if args.json_snake_case:
            self.json_snake_case = True

        for struct in descriptors:
            content += self.generate(struct, args)

        if not filepath.endswith('.go'):
            filepath += '.go'
        filename = os.path.abspath(filepath)

        helper.save_content_if_not_same(filename, content, 'utf-8')
        print('wrote Go source to %s' % filename)

        if args.go_fmt:
            cmd = 'go fmt ' + filename
            goroot = os.getenv('GOROOT')
            if goroot is not None:
                cmd = goroot + '/bin/' + cmd
            print(cmd)
            os.system(cmd)
