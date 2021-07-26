import unittest

from .pcml import *

def parse_tag_line(tag: str):
    """
    tag is a string that contains the tag name, attribute and possibly content
    """
    first_space = tag.find(' ')
    first_bracket = tag.find('(')

    if first_bracket < first_space and first_bracket > 0:
        # we have a bracket to find
        tag[first_bracket:tag.rfind(')')]
    pass

    

div#id.class1 (what type) (btn 25) ()



class TestPCML(unittest.TestCase):
    def test_line_split_1(self):
        cases = [
                ['div(#id.class1.class2)',
                 '<div id="id" class="class1 class2"></div>'],
                ['div(#id type="btn")',
                 '<div id="id" type="btn"></div>'],
                ['div(.class1.class2)', '<div class="class1 class2"></div>'],
                ['div(.class1 type="btn" alt="test")',
                 '<div class="class1" type="btn" alt="test"></div>'],
                ['div(#id.class1) Hello world',
                 '<div id="id" class="class1">Hello world</div>']
                ]

        pass

if __name__ = '__main__'
    unittest.main()
