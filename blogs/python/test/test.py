import unittest
import sys
sys.path.append('..')
import parscppproj

class MyTest(unittest.TestCase):
    def tearDown(self):
        # 每个测试用例执行之后做操作
        print('tearDown')

    def setUp(self):
        # 每个测试用例执行之前做操作
        print('setUp')

    # @classmethod
    # def tearDownClass(self):
    # # 必须使用 @ classmethod装饰器, 所有test运行完后运行一次
    #      print('4444444')
    # @classmethod
    # def setUpClass(self):
    # # 必须使用@classmethod 装饰器,所有test运行前运行一次
    #     print('33333')

    def test_normalized(self):
        parser = parscppproj.ProjClassParser()
        parser.result ={'A':[],'B':['A'],'C':['A'],'D':['B','C']}
        # for k, v in parser.result.items():
        #     print(k)
        parser._normalization_parents()  #
        #{D:[[B,A],[C,A]]}
        self.assertEqual(parser.result['D'],[['B','A'],['C','A']])

        parser.result ={'A':[],'B':['A'],'C':['A'],'D':['B','C'],'E':['D']}
        parser._normalization_parents()
        self.assertEqual(parser.result['E'], [['D',['B','A'],['C','A']]])

if __name__ == '__main__':
    unittest.main()

