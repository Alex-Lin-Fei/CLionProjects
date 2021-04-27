#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

map<string, int> keyword;  //保存32个关键字
map<string, int> ArithmeticOperators; //保存算术运算符
map<string, int> AssignmentOperator; //保存赋值运算符
map<string, int> LogicalOperators; //保存逻辑运算符
map<string, int> RelationalOperators; //保存关系运算符
map<string, int> punctuations; //保存标点符号
map<string, int> escapeCh; //保存转义字符
map<string, int> errorRecord;  //保存词法错误的单词及其符号
map<string, int> countWord; //保存各类单词数
vector<char> vc;

int rows; //语句行数
int characters; //字符总数

//variable
int state; //整型变量，当前状态指示
char ch;  //字符变量，存放当前读入的字符
string token;  //字符数组，存放当前正在识别的单词字符串
int lexemebegin; //字符指针，指向输入缓冲区中当前单词的开始位置
int forward_point; //字符指针，向前指针
char buffer[10240]; //字符数组，输入缓冲区

//process
void get_char(); //根据当前指针forward的指示从输入缓冲区中读取一个字符，并把他放到变量ch中，前移forward
void get_nbc(); // 检查ch是否为空格，若是，反复调用get_char，直到ch为一个非空字符
void cat(); //把ch连接到token
void retract(); //前移forward指针后退一个字符
void error(); //对发现的错误进行相应处理
void Return(const string &); //将识别出来的单词的记号返回给调用程序
void init(const string &, map<string, int> &); //根据相应文件 初始化特定字符表格
string toStr(char ch); //将一个字符转为字符串


void analysis() {
    state = 0;
    do {
//        初始状态
        switch (state) {
            case 0: {
                token = "";
                get_char();
                get_nbc();

//                以字母或下划线开头
                if (isalpha(ch) || ch == '_')
                    state = 1;

//                开头为0  二进制 八进制  十六进制
                else if (ch == '0') {
                    state = 16;
                } else if (isdigit(ch))
                    state = 2;

                else {
                    switch (ch) {
                        case '>':
                        case '<':
                            state = 8;
                            break;
                        case '+':
                        case '-':
                            state = 9;
                            break;
                        case '{':
                        case '}':
                        case '[':
                        case ']':
                        case '(':
                        case ')':
                        case '#':
                        case ':':
                        case ',':
                        case ';':
                        case '?':
                        case '\'':
                        case '\"':
                            state = 10;
                            break;
                        case '/':
                            state = 11;
                            break;
                        case '%':
                        case '^':
                        case '*':
                        case '=':
                        case '!':
                            state = 13;
                            break;
                        case '&':
                        case '|':
                            state = 14;
                            break;
                        case '.':
                            state = 15;
                            break;

//                            处理转义字符
                        case '\\':
                            state = 19;
                            break;
                        case '\n':
                            break;

                        default:
//                            错误状态
                            state = 24;
                            break;
                    }
                }

            }
                break;

//            标识符状态
            case 1: {
                cat();
                get_char();

                if (isdigit(ch) || isalpha(ch) || ch == '_')
                    state = 1;

                else {
//                    标识符识别完成
                    retract();
                    Return(token);
                }
            }
                break;

//            常数状态
            case 2: {
//                2 8 16
                if (ch == '0') {
                    state = 16;
                    break;
                }
                cat();
                get_char();
                if (isdigit(ch))
                    state = 2;

                else if (tolower(ch) == 'u')
                    state = 17;

                else if (tolower(ch) == 'l')
                    state = 18;

                else if (isalpha(ch) && toupper(ch) != 'E' || ch == '_') {
                    retract();
                    error();
                } else {
                    switch (ch) {
                        case '.':
                            state = 3;
                            break;
                        case 'e':
                        case 'E':
                            state = 5;
                            break;
                        default: {
                            retract();
//                            返回整数
                            Return(token);
                            break;
                        }
                    }

                }

            }
                break;

//            小数点状态
            case 3: {
                cat();
                get_char();
                if (isdigit(ch))
                    state = 4;
                else if (isalpha(ch)) {
                    if (tolower(ch) == 'f' || tolower(ch) == 'l')
                        state = 18;
                    else if (tolower(ch) == 'e')
                        state = 5;
                    else {
                        retract();
                        error();
                    }
                } else if (!isalpha(ch) && !isdigit(ch)) {
                    retract();
                    Return(token);
                    state = 0;
                } else {
                    retract();
                    error();
                }
            }
                break;

//            小数状态
            case 4: {
                cat();
                get_char();
                if (isdigit(ch))
                    state = 4;
                else if (isalpha(ch)) {
                    if (tolower(ch) == 'u') {
                        retract();
                        error();
                    } else if (tolower(ch) == 'u' || tolower(ch) == 'l')
                        state = 17;
                    else if (tolower(ch) == 'f')
                        state = 18;

                    else if (tolower(ch) == 'e')
                        state = 5;
                    else {
                        retract();
                        error();
                    }
                } else if (ch == '.') {
                    retract();
                    error();
                } else {
                    retract();
//                     返回小数

                    Return(token);
                }
            }
                break;


//            指数状态
            case 5: {
                cat();
                get_char();
                if (isdigit(ch))
                    state = 7;
                else if (ch == '+' || ch == '-')
                    state = 6;
                else {
                    retract();
                    error();
                }
            }
                break;

//
            case 6: {
                cat();
                get_char();
                if (isdigit(ch))
                    state = 7;
                else if (isalpha(ch)) {
                    if (tolower(ch) == 'l' || tolower(ch) == 'u')
                        state = 17;
                    else if (tolower(ch) == 'f')
                        state = 18;
                    else {
                        retract();
                        error();
                    }
                } else {
                    retract();
                    error();
                    state = 0;
                }
            }
                break;

            case 7: {
                cat();
                get_char();
                if (isdigit(ch))
                    state = 7;
                else if (isalpha(ch) && tolower(ch) == 'u' || tolower(ch) == 'l')
                    state = 17;
                else if (isalpha(ch) && ch == 'f')
                    state = 18;
                else if (isalpha(ch) || ch == '.' || ArithmeticOperators.find(toStr(ch)) != ArithmeticOperators.end()) {
                    retract();
                    error();
                } else {
                    retract();
                    Return(token);
                }
            }
                break;


//            处理'<' '>' 符号
            case 8: {
                cat();
                get_char();

//                返回<= >= << >>记号
                if (ch == '=' || ch == token[token.length() - 1]) {
                    cat();
                    get_char();
                    if (ch == '=') {
                        cat();
                        Return(token);
                    } else {
                        retract();
                        Return(token);
                    }
                } else {
                    retract();
//                    返回< >记号
                    Return(token);
                    break;
                }
            }
                break;

                //             处理 ‘+’ '-'符号
            case 9: {
                cat();
                get_char();
                if (ch == token[token.length() - 1] || ch == '=') {
                    cat();
//                    返回 ’++‘ -- += -=符号
                    Return(token);
                }
//处理 ‘->’符号
                else if (token.back() == '-' && ch == '>') {
                    cat();
                    Return(token);
                }
//                如果是一个数字
                else if (isdigit(ch))
                    state = 2;

//                是个小数
                else if (ch == '.')
                    state = 15;

                else {
//                    返回’+‘ '-'符号
                    retract();
                    Return(token);
                }
            }
                break;


//            处理 {}[]()#:,?; ' "
            case 10: {
                cat();
                Return(token);
            }
                break;


//            '/'状态
            case 11: {
                cat();
                get_char();
//                /* 注释
                if (ch == '*')
                    state = 12;
//                //注释
                else if (ch == '/') {
                    while (ch != '\n')
                        get_char();
                    state = 0;
                } else if (ch == '=') {
//                    返回 '/=' 记号
                    cat();
                    Return(token);
                } else {
                    retract();
//                    返回’/‘记号
                    Return(token);
                }
            }
                break;


//            注释处理状态
            case 12: {
                get_char();
                while (ch != '*')
                    get_char();
                get_char();
                if (ch == '/')
                    state = 0;
                else
                    state = 12;
            }
                break;



//            处理 % *‘ '^' '='符号
            case 13: {
                cat();
                get_char();
                if (ch == '=') {
//                    返回‘%=’ *= ^= ==符号
                    cat();
                    Return(token);
                } else {
                    retract();
//                    返回‘%’ * '^' '='符号
                    Return(token);
                }
            }
                break;

                //            处理’&‘ |符号
            case 14: {
                cat();
                get_char();
                if (ch == token.back() || ch == '=') {
                    cat();
//                    返回’&&‘ || |= ’&=‘符号
                    Return(token);
                } else {
                    retract();
//                    返回& |符号
                    Return(token);
                }
            }
                break;


//                处理 .开头的符号  可能是浮点数
            case 15: {
                cat();
                get_char();
//                是个小数
                if (isdigit(ch)) {
//                    回退
                    state = 4;
//                    token弹出.
//                    token = token.substr(0, token.length() -1);
//                    state = 3;
                }
//                错误
                else {
                    retract();
                    error();
                }
            }
                break;


//            处理 二进制 八进制  十六进制
            case 16: {
                cat();
                get_char();
//                十六进制
                if (tolower(ch) == 'x') {
                    cat();
                    get_char();
                    while (isdigit(ch) || isalpha(ch) && tolower(ch) >= 'a' && tolower(ch) <= 'f') {
                        cat();
                        get_char();
                    }

//                    读取完成
                    if (!isdigit(ch) && !isalpha(ch)) {
                        retract();
                        Return(token);
                    }
//                    处理后缀
                    else if (tolower(ch) == 'u' || tolower(ch) == 'l')
                        state = 17;
//                    错误
                    else {
                        retract();
                        error();
                    }
                }

//                八进制
                else if (isdigit(ch)) {
                    if ('0' <= ch && ch <= '7') {
                        while (isdigit(ch) && '0' <= ch && ch <= '7') {
                            cat();
                            get_char();
                        }
                        if (!isdigit(ch) && !isalpha(ch)) {
                            retract();
                            Return(token);
                        }
                            //                    处理后缀
                        else if (tolower(ch) == 'u' || tolower(ch) == 'l')
                            state = 17;
                        else if (tolower(ch) == 'e')
                            state = 5;
                        else {
                            retract();
                            error();
                        }
                    } else {
                        retract();
                        error();
                    }
                }
//二进制
                else if (tolower(ch) == 'b') {
                    cat();
                    get_char();
                    while (isdigit(ch) && ch >= '0' && ch <= '1') {
                        cat();
                        get_char();
                    }
                    if (!isdigit(ch) && !isalpha(ch)) {
                        retract();
                        Return(token);
                    }
                        //                    处理后缀
                    else if (tolower(ch) == 'u' || tolower(ch) == 'l')
                        state = 17;
                    else if (tolower(ch) == 'e')
                        state = 5;
                    else {
                        retract();
                        error();
                    }
                }
//
                else {
//                    指数
                    if (isalpha(ch)) {
                        if (tolower(ch) == 'e')
                            state = 5;
                        else if (tolower(ch) == 'u' || tolower(ch) == 'l')
                            state = 17;
//                        后缀错误
                        else {
                            retract();
                            error();
                        }
                    }
//                    小数
                    else if (ch == '.') {
                        state = 3;
                    }
//                    标识符错误
                    else if (ch == '_') {
                        retract();
                        error();
                    } else {
                        retract();
                        Return(token);
                    }
                }
            }
                break;

//            处理数字后缀 u l
            case 17: {
                cat();
                get_char();
                if (tolower(ch) == 'u' && token.find('.') != string::npos) {
                    retract();
                    error();
                } else if ((tolower(ch) == 'l' || tolower(ch) == 'u') && tolower(ch) != tolower(token.back()))
                    state = 17;
                else if (!isdigit(ch) && !isalpha(ch)) {
                    retract();
                    Return(token);
                } else {
                    retract();
                    error();
                }
            }
                break;

//            处理字符后缀  f

            case 18: {
                cat();
                get_char();
                if (!isalpha(ch) && !isdigit(ch)) {
                    retract();
                    Return(token);
                } else {
                    retract();
                    error();
                }

            }
                break;


//            处理转义字符
            case 19: {
                cat();
                get_char();
                switch (ch) {
                    case 'a':
                    case 'b':
                    case 'f':
                    case 'n':
                    case 'r':
                    case 't':
                    case '\\':
                    case 'v': {
                        cat();
                        Return(token);
                    }
                        break;
                    case '\'':
                    case '\"':
                    case '?': {
                        string s;
                        s += ch;
                        token = s;
                        Return(token);
                        break;
                    }
                    default:
                        retract();
                        error();
                }
            }
                break;


//            错误处理状态
            case 24:
                error();
                break;
        }

    } while (ch != '\0');
}


int main() {
//    初始化关键字和操作符
    init("keyword.txt", keyword);
    init("ArithmeticOperators.txt", ArithmeticOperators);
    init("AssignmentOperator.txt", AssignmentOperator);
    init("LogicalOperators.txt", LogicalOperators);
    init("RelationalOperators.txt", RelationalOperators);
    init("punctuation.txt", punctuations);
    init("escapeChar.txt", escapeCh);


//    读取程序文件
    memset(buffer, '\0', sizeof(buffer));
    ifstream fin;
    fin.open("/home/lilin/temp.txt");
    if (fin.is_open()) {

//        保存至缓冲区
        fin.getline(buffer, 10240, ios::skipws);
        fin.close();

//        分析
        cout << "analysis result:\n";
        cout << "----------------------------------------------------\n";
        analysis();

        cout << "----------------------------------------------------\n";
        cout << "lexical mistake: " << endl;
//        输出词法错误
        for (auto &iter: errorRecord)
            cout << "string: " << iter.first << " row: " << iter.second << endl;

        cout << "----------------------------------------------------\n";
        cout << "statistical results:" << endl;
//        输出统计结果
        cout << "rows:" << rows << " " << "characters: " << characters << endl;

        for (auto &c: countWord)
            cout << "category: " << c.first << " number: " << c.second << endl;

    } else
        cout << "cannot open file" << endl;

    return 0;
}


//根据当前指针forward的指示从输入缓冲区中读取一个字符，并把他放到变量ch中，前移forward
void get_char() {
    characters++;
    ch = buffer[forward_point++];
    vc.push_back(ch);
    if (ch == '\n')
        rows++;
}

// 检查ch是否为空格，若是，反复调用get_char，直到ch为一个非空字符
void get_nbc() {
    while (ch == ' ')
        get_char();

    lexemebegin = forward_point - 1;
}

//把ch连接到token
void cat() {
    token += ch;
}

//前移forward指针后退一个字符
void retract() {
    if (ch == '\n')
        rows--;
    ch = buffer[--forward_point - 1];
    characters--;
    vc.pop_back();
}


//对发现的错误进行相应处理
void error() {
    get_char();

    while (ch != ' ' && punctuations.find(toStr(ch)) == punctuations.end()) {
        if (ch == '\0' || ch == '\n')
            break;
        cat();
        get_char();
    }
    retract();
    if (errorRecord.find(token) == errorRecord.end())
        errorRecord.insert({token, rows + 1});
    state = 24;
    Return(token);
    lexemebegin = forward_point - 1;
    state = 0;
}


//将识别出来的单词的记号返回给调用程序
void Return(const string &str) {
    string cls;

//    判断记号类型 并为各类单词计数
    if (keyword.find(str) != keyword.end())
        cls = "keyword-" + to_string(keyword[str]);
    else if (ArithmeticOperators.find(str) != ArithmeticOperators.end())
        cls = "ArithmeticOperators-" + to_string(ArithmeticOperators[str]);
    else if (AssignmentOperator.find(str) != AssignmentOperator.end())
        cls = "AssignmentOperators-" + to_string(AssignmentOperator[str]);
    else if (LogicalOperators.find(str) != LogicalOperators.end())
        cls = "LogicalOperators-" + to_string(LogicalOperators[str]);
    else if (RelationalOperators.find(str) != RelationalOperators.end())
        cls = "RelationalOperators-" + to_string(RelationalOperators[str]);
    else if (punctuations.find(str) != punctuations.end())
        cls = "punctuations-" + to_string(punctuations[str]);
    else if (escapeCh.find(str) != escapeCh.end())
        cls = "escapeCh-" + to_string(escapeCh[str]);
    else {
        if (state == 1)
            cls = "token";
        else if (state >= 2 && state <= 7 || 16 <= state && state <= 18)
            cls = "NUM";
        else if (str == "?")
            cls = "ConditionalOperators";
        else if (str == ",")
            cls = "comma";
        else if (state == 24)
            cls = "error";
        else if (str == "?")
            cls = "ConditionalOperator";
        else if (str == "#")
            cls = "definition";
        else if(str == "->")
            cls = "probe";
    }
    countWord[cls]++;


//    输出记号
    cout << "( " << str << ", " << cls << " )" << endl;

//    移动指针
    lexemebegin = forward_point;
//    重置初始状态
    state = 0;
}

void init(const string &file, map<string, int> &m) {
    ifstream fin;
    int id = 1;

//    读取关键字
    fin.open("/home/lilin/" + file);
    if (fin.is_open()) {
        string s;
        while (getline(fin, s))
            m.insert({s, id++});
        fin.close();
    } else
        cout << "cannot open file" << endl;
}

string toStr(char ch) {
    string s;
    s += ch;
    return s;
}