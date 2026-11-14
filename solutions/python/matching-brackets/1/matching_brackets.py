def is_paired(input_string):
    stack = []
    for i in range(len(input_string)):
        if input_string[i] in "[{(":
            stack.append(input_string[i])
        elif input_string[i] == '}':
            if not stack or stack.pop() != '{':
                return False
        elif input_string[i] == ']':
            if not stack or stack.pop() != '[':
                return False
        elif input_string[i] == ')':
            if not stack or stack.pop() != '(':
                return False
    if len(stack) > 0:
        return False
    return True