
def basic_calculate(expression):
    i = 0 # 当前字符编号
    num_sign = '+' # num前面的符号
    num = 0# 解析出来的数字
    stk = []# 保存所有解析出来的num
    while i < len(expression):
        cc = expression[i]
        # 如果当前字符是数字,则落入下面的if block中.
        if cc.isdigit():
            num = num * 10 + int(cc)
        # 如果当前字符是操作符或者当前字符是最后一个字符,则触发填充栈操作,更新sign并初始化num.
        if cc in ['-', '+'] or i == len(expression) - 1:
            if num_sign == '-':
                stk.append(-num)
            elif num_sign == '+':
                stk.append(num)
            # 更新 num_sign和num
            num_sign = cc
            num = 0
        i += 1        
        # 如果是空格,则不做任何处理,进入下一个循环.
    print(f'stack:{stk}')
    return sum(stk)

def median_calculate(expression):
    i = 0 # 当前字符编号
    num = 0# num前面的符号
    num_sign = '+'
    stk = []
    while i < len(expression):
        cc = expression[i]
        if cc.isdigit():
            num = num * 10 + int(cc)
        # 如果当前字符是操作符或者当前字符是最后一个字符,则触发填充栈操作,需要对val进行操作(push到栈里?还是直接替换栈的最后一个数字?)
        if cc in ['-', '+', '*', '/'] or i == len(expression) - 1:
            if num_sign == '-':
                stk.append(-num)
            elif num_sign == '+':
                stk.append(num)
            # 针对*/添加的判断
            elif num_sign == '*':
                stk[-1] *= num
            elif num_sign == '/':
                stk[-1] = int(stk[-1] / num)
            num_sign = cc
            num = 0
        i += 1
    print(f'stack:{stk}')
    return sum(stk)

def median_calculate_with_stack(expression):
    num = 0# num前面的符号
    num_sign = '+'
    stk = []
    while len(expression) > 0:
        cc = expression.pop(0)
        if cc.isdigit():
            num = num * 10 + int(cc)
        # 如果当前字符是操作符或者当前字符是最后一个字符,则触发填充栈操作,需要对val进行操作(push到栈里?还是直接替换栈的最后一个数字?)
        if cc in ['-', '+', '*', '/'] or len(expression) == 0:
            if num_sign == '-':
                stk.append(-num)
            elif num_sign == '+':
                stk.append(num)
            # 针对*/添加的判断
            elif num_sign == '*':
                stk[-1] *= num
            elif num_sign == '/':
                stk[-1] = int(stk[-1] / num)
            num_sign = cc
            num = 0
    print(f'stack:{stk}')
    return sum(stk) 

def expert_calculate(expression):
    num_sign = '+'# num前面的符号
    num = 0
    stk = []
    while len(expression) > 0:
        cc = expression.pop(0)
        if cc.isdigit():
            num = num * 10 + int(cc)
        if cc == '(':
            num = expert_calculate(expression)
        # 如果当前字符是操作符或者当前字符是最后一个字符,则触发填充栈操作,需要对val进行操作(push到栈里?还是直接替换栈的最后一个数字?)
        if cc in ['-', '+', '*', '/', '(', ')'] or len(expression) == 0:
            if num_sign == '-':
                stk.append(-num)
            elif num_sign == '+':
                stk.append(num)
            # 针对*/添加的判断
            elif num_sign == '*':
                stk[-1] *= num
            elif num_sign == '/':
                stk[-1] = int(stk[-1] / num)
            num_sign = cc
            num = 0
        if cc == ')':
            break
    print(f'stack:{stk}')
    return sum(stk) 

if __name__ == '__main__':
    txt = '1-12+ 3'
    result = basic_calculate(txt)
    # stack:[1, -12, 3]
    print(f'result:{result}')
    assert  result == -8

    txt = '3 * 4 - 5/2 - 6' # 12-2-6 = 4
    result = median_calculate(txt)
    result_with_stack = median_calculate_with_stack(list(txt))
    print(f'result:{result}, {result_with_stack}')
    assert  result == 4 and result_with_stack ==4

    txt = '3* (4-5/2) -6' # 3*2 - 6 = 0
    result = expert_calculate(list(txt))
    print(f'result:{result}')
    assert result == 0