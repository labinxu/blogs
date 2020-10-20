from abcmart import abcmart

if __name__=='__main__':
    site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
    site.login('flow@gmail.com','juyoujin110')
    import pdb;pdb.set_trace()
    site.addcart('g6069610001049')