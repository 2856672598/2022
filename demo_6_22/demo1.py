import os

filename = 'student.txt'


def menu():
    print('----------学生成绩管理系统-------------')
    print('\t\t\t\t1.录入学生信息')
    print('\t\t\t\t2.查找学生信息')
    print('\t\t\t\t3.修改学生信息')
    print('\t\t\t\t4.删除学生信息')
    print('\t\t\t\t5.统计学生人数')
    print('\t\t\t\t6.显示所有学生信息')
    print('\t\t\t\t0.退出')


def save(list):
    try:
        file = open(filename, 'a', encoding='utf-8')
    except:
        file = open(filename, 'w', encoding='utf-8')
    for item in list:
        file.write(str(item) + '\n')
    file.close()


def insert():
    stu_list = []
    while True:
        id = input('输入学生的ID:')
        name = input('输入学生的姓名')
        try:
            english = int(input('输入英语成绩：'))
            java = int(input('输入Java成绩：'))
            python = int(input('输入python成绩：'))
        except:
            print('输入的成绩不是数字，请重新输入')
            continue
        # 输入合法 构建字典
        stu_list.append({'id': id, 'name': name, 'english': english, 'java': java, 'python': python})
        choose = input('录入成功，是否继续录入（Y,N）:')
        if choose == 'N':
            break
    # 将录入的信息保存文件
    save(stu_list)


def show_student(li):
    if len(li) == 0:
        print('暂无学生信息')
    else:
        str = '{:^6}\t{:^12}\t{:^8}\t\t{:^10}\t\t{:^10}'
        print(str.format('学号', '姓名', '英语成绩', 'Java成绩', 'python成绩'))
        for item in li:
            print(str.format(item.get('id')
                             , item.get('name')
                             , item.get('english')
                             , item.get('java')
                             , item.get('python')))


def find():
    stu_list = []
    while True:
        if not os.path.exists(filename):
            print('文件未保存学生信息')
        else:
            with open(filename, 'r', encoding='utf-8') as file:
                students = file.readlines()
                if len(students) == 0:
                    print('学生信息为空')
                    return
                choose = int(input('1.按学号查找，2.按姓名查找\n'))
                if choose == 1:
                    id = input('您要查找的学号:')
                    for item in students:
                        li = dict(eval(item))
                        if li.get('id') == id:
                            stu_list.append(li)
                elif choose == 2:
                    name = input('输入您要查找的姓名:')
                    for item in students:
                        li = dict(eval(item))
                        if li.get('name') == name:
                            stu_list.append(li)
                else:

                    print('选择错误，请重新输入')
                    continue
                show_student(stu_list)
                stu_list.clear()
                choose = input('是否需要继续查找（Y/N）')
                if choose == 'N':
                    break


def modify():
    stu_list = []
    if not os.path.exists(filename):
        print('没有学生信息')
        return
    else:
        with open(filename, 'r+', encoding='utf-8') as file:
            students = file.readlines()
            for item in students:
                stu_list.append(eval(item))
            while True:
                id = input('输入您要修改的学生ID')
                for item in stu_list:
                    if item['id'] == id:

                        item['name'] = input('输入修改后的姓名:')
                        try:
                            item['english'] = int(input('输入修改后的英语成绩:'))
                            item['java'] = int(input('输入修改后的java成绩:'))
                            item['python'] = int(input('输入修改后的python成绩:'))
                            print('修改成功')
                        except:
                            print('成绩输入无效')
                            break
                choose = input('是否需要继续修改，Y/N')
                if choose != 'Y':
                    break
    with open(filename, 'w', encoding='utf-8') as file:
        for item in stu_list:
            file.write(str(item) + '\n')


def delete():
    stu_list = []
    if not os.path.exists(filename):
        print('没有学生信息')
        return
    else:
        with open(filename, 'r+', encoding='utf-8') as file:
            students = file.readlines()
            for item in students:
                stu_list.append(eval(item))
            while True:
                id = input('输入您要删除的学生ID:')
                for item in stu_list:
                    if item['id'] == id:
                        stu_list.remove(item)
                        print('删除成功')
                        break
                show_student(stu_list)
                choose = input('是否继续删除（Y/N）:')
                if choose != 'Y':
                    break
    # 写入到文件
    with open(filename, 'w', encoding='utf-8') as file:
        for item in stu_list:
            file.write(str(item) + '\n')


def statistics():
    if not os.path.exists(filename):
        print('没有学生信息')
        return
    else:
        with open(filename, 'r', encoding='utf-8') as file:
            students = file.readlines()
            print(f'总计{len(students)}人。')


def show():
    if not os.path.exists(filename):
        print('没有学生信息')
        return
    else:
        with open(filename, 'r', encoding='utf-8') as file:
            stu_list = []
            students = file.readlines()
            if len(students) == 0:
                print('未录入学生信息')
                return
            else:
                for item in students:
                    stu_list.append(eval(item))
                if stu_list:
                    show_student(stu_list)


def main():
    while True:
        menu()
        choose = int(input('请选择:'))
        if choose in [0, 1, 2, 3, 4, 5, 6]:
            if choose == 0:
                print('退出程序')
                break
            elif choose == 1:
                insert()
            elif choose == 2:
                find()
            elif choose == 3:
                modify()
            elif choose == 4:
                delete()
            elif choose == 5:
                statistics()
            elif choose == 6:
                show()
        else:
            print('输入错误，请重新选择')
            continue



if __name__ == '__main__':
    main()

