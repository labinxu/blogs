def testkargs(**kwargs):
    key = kwargs.pop('key',None)
    print(key)

def invoke(**kwargs):
    testkargs(**kwargs)


invoke(key1=['a','b'])
