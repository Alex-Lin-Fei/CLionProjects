#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

map<string, int> keyword;  //����32���ؼ���
map<string, int> ArithmeticOperators; //�������������
map<string, int> AssignmentOperator; //���渳ֵ�����
map<string, int> LogicalOperators; //�����߼������
map<string, int> RelationalOperators; //�����ϵ�����
map<string, int> punctuations; //���������
map<string, int> escapeCh; //����ת���ַ�
map<string, int> errorRecord;  //����ʷ�����ĵ��ʼ������
map<string, int> countWord; //������൥����
vector<char> vc;

int rows; //�������
int characters; //�ַ�����

//variable
int state; //���ͱ�������ǰ״ָ̬ʾ
char ch;  //�ַ���������ŵ�ǰ������ַ�
string token;  //�ַ����飬��ŵ�ǰ����ʶ��ĵ����ַ���
int lexemebegin; //�ַ�ָ�룬ָ�����뻺�����е�ǰ���ʵĿ�ʼλ��
int forward_point; //�ַ�ָ�룬��ǰָ��
char buffer[10240]; //�ַ����飬���뻺����

//process
void get_char(); //���ݵ�ǰָ��forward��ָʾ�����뻺�����ж�ȡһ���ַ����������ŵ�����ch�У�ǰ��forward
void get_nbc(); // ���ch�Ƿ�Ϊ�ո����ǣ���������get_char��ֱ��chΪһ���ǿ��ַ�
void cat(); //��ch���ӵ�token
void retract(); //ǰ��forwardָ�����һ���ַ�
void error(); //�Է��ֵĴ��������Ӧ����
void Return(const string &); //��ʶ������ĵ��ʵļǺŷ��ظ����ó���
void init(const string &, map<string, int> &); //������Ӧ�ļ� ��ʼ���ض��ַ����
string toStr(char ch); //��һ���ַ�תΪ�ַ���


void analysis() {
    state = 0;
    do {
//        ��ʼ״̬
        switch (state) {
            case 0: {
                token = "";
                get_char();
                get_nbc();

//                ����ĸ���»��߿�ͷ
                if (isalpha(ch) || ch == '_')
                    state = 1;

//                ��ͷΪ0  ������ �˽���  ʮ������
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

//                            ����ת���ַ�
                        case '\\':
                            state = 19;
                            break;
                        case '\n':
                            break;

                        default:
//                            ����״̬
                            state = 24;
                            break;
                    }
                }

            }
                break;

//            ��ʶ��״̬
            case 1: {
                cat();
                get_char();

                if (isdigit(ch) || isalpha(ch) || ch == '_')
                    state = 1;

                else {
//                    ��ʶ��ʶ�����
                    retract();
                    Return(token);
                }
            }
                break;

//            ����״̬
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
//                            ��������
                            Return(token);
                            break;
                        }
                    }

                }

            }
                break;

//            С����״̬
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

//            С��״̬
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
//                     ����С��

                    Return(token);
                }
            }
                break;


//            ָ��״̬
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


//            ����'<' '>' ����
            case 8: {
                cat();
                get_char();

//                ����<= >= << >>�Ǻ�
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
//                    ����< >�Ǻ�
                    Return(token);
                    break;
                }
            }
                break;

                //             ���� ��+�� '-'����
            case 9: {
                cat();
                get_char();
                if (ch == token[token.length() - 1] || ch == '=') {
                    cat();
//                    ���� ��++�� -- += -=����
                    Return(token);
                }
//���� ��->������
                else if (token.back() == '-' && ch == '>') {
                    cat();
                    Return(token);
                }
//                �����һ������
                else if (isdigit(ch))
                    state = 2;

//                �Ǹ�С��
                else if (ch == '.')
                    state = 15;

                else {
//                    ���ء�+�� '-'����
                    retract();
                    Return(token);
                }
            }
                break;


//            ���� {}[]()#:,?; ' "
            case 10: {
                cat();
                Return(token);
            }
                break;


//            '/'״̬
            case 11: {
                cat();
                get_char();
//                /* ע��
                if (ch == '*')
                    state = 12;
//                //ע��
                else if (ch == '/') {
                    while (ch != '\n')
                        get_char();
                    state = 0;
                } else if (ch == '=') {
//                    ���� '/=' �Ǻ�
                    cat();
                    Return(token);
                } else {
                    retract();
//                    ���ء�/���Ǻ�
                    Return(token);
                }
            }
                break;


//            ע�ʹ���״̬
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



//            ���� % *�� '^' '='����
            case 13: {
                cat();
                get_char();
                if (ch == '=') {
//                    ���ء�%=�� *= ^= ==����
                    cat();
                    Return(token);
                } else {
                    retract();
//                    ���ء�%�� * '^' '='����
                    Return(token);
                }
            }
                break;

                //            ����&�� |����
            case 14: {
                cat();
                get_char();
                if (ch == token.back() || ch == '=') {
                    cat();
//                    ���ء�&&�� || |= ��&=������
                    Return(token);
                } else {
                    retract();
//                    ����& |����
                    Return(token);
                }
            }
                break;


//                ���� .��ͷ�ķ���  �����Ǹ�����
            case 15: {
                cat();
                get_char();
//                �Ǹ�С��
                if (isdigit(ch)) {
//                    ����
                    state = 4;
//                    token����.
//                    token = token.substr(0, token.length() -1);
//                    state = 3;
                }
//                ����
                else {
                    retract();
                    error();
                }
            }
                break;


//            ���� ������ �˽���  ʮ������
            case 16: {
                cat();
                get_char();
//                ʮ������
                if (tolower(ch) == 'x') {
                    cat();
                    get_char();
                    while (isdigit(ch) || isalpha(ch) && tolower(ch) >= 'a' && tolower(ch) <= 'f') {
                        cat();
                        get_char();
                    }

//                    ��ȡ���
                    if (!isdigit(ch) && !isalpha(ch)) {
                        retract();
                        Return(token);
                    }
//                    �����׺
                    else if (tolower(ch) == 'u' || tolower(ch) == 'l')
                        state = 17;
//                    ����
                    else {
                        retract();
                        error();
                    }
                }

//                �˽���
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
                            //                    �����׺
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
//������
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
                        //                    �����׺
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
//                    ָ��
                    if (isalpha(ch)) {
                        if (tolower(ch) == 'e')
                            state = 5;
                        else if (tolower(ch) == 'u' || tolower(ch) == 'l')
                            state = 17;
//                        ��׺����
                        else {
                            retract();
                            error();
                        }
                    }
//                    С��
                    else if (ch == '.') {
                        state = 3;
                    }
//                    ��ʶ������
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

//            �������ֺ�׺ u l
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

//            �����ַ���׺  f

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


//            ����ת���ַ�
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


//            ������״̬
            case 24:
                error();
                break;
        }

    } while (ch != '\0');
}


int main() {
//    ��ʼ���ؼ��ֺͲ�����
    init("keyword.txt", keyword);
    init("ArithmeticOperators.txt", ArithmeticOperators);
    init("AssignmentOperator.txt", AssignmentOperator);
    init("LogicalOperators.txt", LogicalOperators);
    init("RelationalOperators.txt", RelationalOperators);
    init("punctuation.txt", punctuations);
    init("escapeChar.txt", escapeCh);


//    ��ȡ�����ļ�
    memset(buffer, '\0', sizeof(buffer));
    ifstream fin;
    fin.open("/home/lilin/temp.txt");
    if (fin.is_open()) {

//        ������������
        fin.getline(buffer, 10240, ios::skipws);
        fin.close();

//        ����
        cout << "analysis result:\n";
        cout << "----------------------------------------------------\n";
        analysis();

        cout << "----------------------------------------------------\n";
        cout << "lexical mistake: " << endl;
//        ����ʷ�����
        for (auto &iter: errorRecord)
            cout << "string: " << iter.first << " row: " << iter.second << endl;

        cout << "----------------------------------------------------\n";
        cout << "statistical results:" << endl;
//        ���ͳ�ƽ��
        cout << "rows:" << rows << " " << "characters: " << characters << endl;

        for (auto &c: countWord)
            cout << "category: " << c.first << " number: " << c.second << endl;

    } else
        cout << "cannot open file" << endl;

    return 0;
}


//���ݵ�ǰָ��forward��ָʾ�����뻺�����ж�ȡһ���ַ����������ŵ�����ch�У�ǰ��forward
void get_char() {
    characters++;
    ch = buffer[forward_point++];
    vc.push_back(ch);
    if (ch == '\n')
        rows++;
}

// ���ch�Ƿ�Ϊ�ո����ǣ���������get_char��ֱ��chΪһ���ǿ��ַ�
void get_nbc() {
    while (ch == ' ')
        get_char();

    lexemebegin = forward_point - 1;
}

//��ch���ӵ�token
void cat() {
    token += ch;
}

//ǰ��forwardָ�����һ���ַ�
void retract() {
    if (ch == '\n')
        rows--;
    ch = buffer[--forward_point - 1];
    characters--;
    vc.pop_back();
}


//�Է��ֵĴ��������Ӧ����
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


//��ʶ������ĵ��ʵļǺŷ��ظ����ó���
void Return(const string &str) {
    string cls;

//    �жϼǺ����� ��Ϊ���൥�ʼ���
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


//    ����Ǻ�
    cout << "( " << str << ", " << cls << " )" << endl;

//    �ƶ�ָ��
    lexemebegin = forward_point;
//    ���ó�ʼ״̬
    state = 0;
}

void init(const string &file, map<string, int> &m) {
    ifstream fin;
    int id = 1;

//    ��ȡ�ؼ���
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