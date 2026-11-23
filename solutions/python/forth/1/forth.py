import array

class StackUnderflowError(Exception):
    """Exception raised when Stack is not full.
       message: explanation of the error.
    """
    pass

def evaluate(input_data):
    if input_data[-1].startswith(": "):
        raise ValueError("illegal operation")
    lst = input_data[-1].lower().split()
    definitions = {}
    if len(input_data) > 1:
        for str in input_data[:-1]:
            name, *definition = str.strip(":; ").lower().split()
            i = 0
            if name.lstrip('-').isdigit():
                raise ValueError("illegal operation")
            while i < len(definition):
                if definition[i] in definitions:
                    strs = definitions[definition[i]]
                    definition[i:i] = strs
                    definition.pop(i + len(strs))
                i += 1
            definitions[name] = definition
    stack = array.array('i')
    i = 0
    while i < len(lst):
        if lst[i] in definitions:
            strs = definitions[lst[i]]
            lst[i:i] = strs
            lst.pop(i + len(strs))
        if lst[i].lstrip('-').isdigit():
            stack.append(int(lst[i]))
        elif lst[i] in "+-*/":
            if len(stack) < 2:
                raise StackUnderflowError("Insufficient number of items in stack")
            y = stack.pop()
            x = stack.pop()
            match lst[i]:
                case '+': stack.append(x + y)
                case '-': stack.append(x - y)
                case '*': stack.append(x * y)
                case '/': 
                    if y == 0:
                        raise ZeroDivisionError("divide by zero")
                    stack.append(x // y)
        elif lst[i].lower() == "dup":
            if len(stack) == 0:
                raise StackUnderflowError("Insufficient number of items in stack")
            stack.append(stack[-1])
        elif lst[i].lower() == "drop":
            if len(stack) == 0:
                raise StackUnderflowError("Insufficient number of items in stack")
            stack.pop()
        elif lst[i].lower() == "swap":
            if len(stack) < 2:
                raise StackUnderflowError("Insufficient number of items in stack")
            stack[-1], stack[-2] = stack[-2], stack[-1]
        elif lst[i].lower() == "over":
            if len(stack) < 2:
                raise StackUnderflowError("Insufficient number of items in stack")
            stack.append(stack[-2])
        else:
            raise ValueError("undefined operation")
        i += 1
    return stack.tolist()