from abcmart import abcmart
import sys
if __name__=='__main__':
    site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
    if not site.login('flowair@gmail.com','wukong110'):
        sys.exit(1)
    import pdb;pdb.set_trace()
    site.addcart('g6069610001049')