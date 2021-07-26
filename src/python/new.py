def tokenize(chars: str) -> list:
    "Convert a string of characters into a list of tokens."
    return chars.replace('(', ' ( ').replace(')', ' ) ').split()


def find_next_close(tokens: list, start_pos: int) -> int:
    depth = 0
    end_pos = 0
    for index, value in enumerate(tokens[start_pos:]):
        if value == ')' and depth == 0:
            return start_pos+index
        elif value == '(':
            depth += 1
        elif value == ')' and depth > 0:
            depth -= 1
            end_pos = start_pos+index
    if depth == 0: 
        return end_pos


class Element:
    def __init__(self, raw: str):
        self.raw = raw
        self.tag = ''
        self.attrs = []
        self.content = ''
        self.classes = []
        self.id = ''

def read_brackets(tokens: list, current_index: int, element: Element):
    if current_index >= len(tokens):
        return element
    value = tokens[current_index]
    if value == '(':
        end_pos = find_next_close(tokens, current_index+1)
        if end_pos is not None:
            print(tokens[current_index+1:end_pos])
            element.attrs.append(tokens[current_index+1:end_pos])
            return read_brackets(tokens, end_pos, element)
    else:
        return read_brackets(tokens, current_index+1, element)


def split_id_class(token: str, char: str):
    classes = tokens[0].find(char)
    if classes > 0:
        c = tokens[0][classes+1:].split(char)
        el.classes = c


def parse(string: str):
    el = Element(string)
    tokens = tokenize(string)


    ids = tokens[0].find('#')
    if ids > 0:
        i = tokens[0][ids+1:].split('#')
        el.id = i
        
    return read_brackets(tokens=tokens, current_index=0, element=el)

s = "div#id.class1.class2 (what type) (onclick function('hello' 25)) ()"
element = parse(s)
print(element.__dict__)




