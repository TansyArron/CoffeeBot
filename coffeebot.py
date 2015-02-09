import zulip
import json
import requests
import random
import os
import socket

ZULIP_USERNAME = 'CoffeeBot-bot@students.hackerschool.com'
ZULIP_API_KEY = 'x9B2OV00fgbgT5BOcXlJawDNv7OSfQAt'
HOST = '' #remote host
PORT = 5000
SOCK = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
SOCK.bind((HOST, PORT))
SOCK.listen()

# create a Zulip client/bot
client = zulip.Client(email=ZULIP_USERNAME,
                      api_key=ZULIP_API_KEY)

# call Zulip API to get list of all streams
def get_zulip_streams():
    response = requests.get(
        'https://api.zulip.com/v1/streams',
        auth=requests.auth.HTTPBasicAuth(ZULIP_USERNAME, ZULIP_API_KEY)
    )
    if response.status_code == 200:
        return

    elif response.status_code == 401:
        raise RuntimeError('check yo auth')

    else:
        raise RuntimeError(':( we failed to GET streams.\n(%s)' % response)


def subscribe():
    ''' subscribe to 455 Broadway
    '''
    client.add_subscriptions([{'name': u'bot-test'}])
    # client.add_subscriptions([{'name': u'455 Broadway'}])

def send_message(msg):
    '''    
        post to 455 Broadway.
    '''
    client.send_message({
        "type": "stream",
        "subject": "CoffeeCoffeeCoffeeCoffee!",
        "to": "bot-test",
        "content": msg
    })
    print 'send'

get_zulip_streams()
subscribe()
send_message('COFFEE!')

''' listen for arduino
    if light value changes, do stuff.
'''

'''
    post coffee gif?
'''
