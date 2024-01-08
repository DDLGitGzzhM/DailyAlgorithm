import json

import ruamel.yaml
from baseopensdk import BaseClient
from baseopensdk.api.base.v1 import *
from dotenv import load_dotenv, find_dotenv
from ruamel.yaml.scalarstring import FoldedScalarString
import argparse
import datetime
yaml = ruamel.yaml.YAML()

load_dotenv(find_dotenv())

# 从多维表格url中获取https://onetoken.feishu.cn/base/{app_token}?table={table_id}
# 举例：https://onetoken.feishu.cn/base/MBvDb8WudaDkrusQ3hCcAPSCn1x?table=tbliku1QIjtUu2ey&view=vewWu3EnIS
APP_TOKEN = 'MBvDb8WudaDkrusQ3hCcAPSCn1x'
TABLE_ID = 'tbliku1QIjtUu2ey'
# 多维表格 -> 右上角 拓展脚本 -> 获取授权码
PERSONAL_BASE_TOKEN = 'pt-xxx'


def get_sheet_records(app_token=APP_TOKEN, base_token=None, table_id=TABLE_ID):
    if base_token is None :
        base_token = PERSONAL_BASE_TOKEN
    client: BaseClient = BaseClient.builder() \
        .app_token(app_token) \
        .personal_base_token(base_token) \
        .build()

    list_record_request = ListAppTableRecordRequest.builder() \
        .page_size(1000) \
        .table_id(table_id) \
        .build()

    list_record_response = client.base.v1.app_table_record.list(list_record_request)
    records = getattr(list_record_response.data, 'items', [])
    return client, records

def update_yml(exchange):
    client, records = get_sheet_records()
    res = {
        'snippets': []
    }

    yaml.indent(mapping=2, sequence=4, offset=2)
    yaml.preserve_quotes = True
    for r in records:
        if r.fields['Exchange'] == exchange:
            d = {
                'name': r.fields['name'],
                'code': FoldedScalarString(r.fields['code'].rstrip('\n') + '\n')
            }
            res['snippets'].append(d)
    with open(f'play/gzmplay/{exchange}.yml', 'w') as f:
        yaml.dump(res, f)

    china_timezone = datetime.timezone(datetime.timedelta(hours=8))
    timestamp = datetime.datetime.now(china_timezone).strftime("%Y-%m-%d %H:%M:%S")  # 获取当前时间戳
    comment = f"# Updated at: {timestamp}"  # 创建注释行
    with open(f'play/gzmplay/{exchange}.yml', 'w') as f:
        f.write(comment + '\n')  # 写入注释行
        yaml.dump(res, f)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='manual to this script')
    parser.add_argument('--token', type=str, default='', help='token', required=True)
    args = parser.parse_args()

    PERSONAL_BASE_TOKEN = args.token

    client, records = get_sheet_records()
    res = {
        'snippets': []
    }

    exchanges = set()
    for r in records:
        exg = r.fields['Exchange']
        exchanges.add(exg)

    for exg in exchanges:
        update_yml(exg)

    print('finished update yml!')