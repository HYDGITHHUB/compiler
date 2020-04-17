package compiler_test;
import java.util.Scanner;

public class Test_01 {
    static String name; // 存放常量名
    static String value;// 存放常量值
    static String type; // 存放常量值类型
    static String errorInfo;// 存放错误信息
    static int correctName;// 0表示常量名错误，1表示常量名正确
    static int correctValue;// 0表示常量值错误，1表示常量值正确
    static int int_num = 0;
    static int string_num = 0;
    static int float_num = 0;
    static int char_num = 0;// 用于统计各种类型的常量数量

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        s = s.trim();// 去除首尾空格
        boolean result = s.startsWith("const") && s.endsWith(";");
        while (!result) {
            // 如果输入字符串不是以“const"开头并且以”；”结尾，则输出错误信息，并且要求重新输入
            System.out.println("It is not a constant declaration statement! ");
            System.out.println("Please input a string again!");
            s = in.nextLine();
            s = s.trim();
            result = s.startsWith("const") && s.endsWith(";");
        }
        Output(s);
        in.close();
    }

    // 判断常量名是否合法
    public static int checkName(char[] a, int i) {
        name = "";
        while (a[i] != '=') {
            name += a[i];
            i++;
        }
        name = name.trim();
        String regex = "[a-zA-Z_][a-zA-Z0-9_]*";
        boolean result = name.matches(regex);
        if (result) {
            correctName = 1;
        } else {
            correctName = 0;
        }
        return i;
    }

    // 判断常量值的合法性与常量类型
    public static int checkType(char a[], int i) {
        value = "";
        errorInfo = "";
        while (a[i] != ',' && a[i] != ';') {
            value += a[i];
            i++;
        }
        value = value.trim();
        if (correctName == 1) {
            // 判断该数是否为整数
            if (value.matches("[+|-]?[0-9]*")) {
                String s1 = value;
                // 判断符号
                if (value.charAt(0) == '+' || value.charAt(0) == '-') {
                    s1 = value.substring(1);
                }
                if (s1.equals("0") || s1.matches("[1-9][0-9]*")) {
                    correctValue = 1;
                    type = "integer";
                    int_num++;
                } else {
                    errorInfo = "Wrong! The integer can’t be started with ‘0’.";
                    correctValue = 0;
                }
            }
            // 判断该数是否为浮点数
            else if (value.matches("[+|-]?[0-9]*[.][0-9]+")) {
                correctValue = 1;
                type = "float";
                float_num++;
            }

            // 判断常量值是char型
            else if (value.startsWith("'") && value.endsWith("'")) {
                if (value.length() == 3) {
                    correctValue = 1;
                    type = "char";
                    char_num++;
                } else {
                    errorInfo += "Wrong! There are  more than one char in ‘’.";
                    correctValue = 0;
                }
            }

            // 判断常量名是String型
            else if (value.startsWith("\"") && value.endsWith("\"")) {
                correctValue = 1;
                type = "string";
                string_num++;
            }

            // 其他错误情况
            else {
                correctValue = 0;
                errorInfo += "Wrong! The format of the value string is not correct !";
            }
        }
        return i;
    }

    static void Output(String s) {
        char[] str = s.toCharArray();
        int i = 5;
        while (i < str.length - 1) {
            i = checkName(str, i);
            i = checkType(str, i + 1) + 1;
            // 常量名定义正确，继续判断常量值
            if (correctName == 1) {
                // 常量值正确，输出结果，包含常量名，常量类型以及常量值
                if (correctValue == 1) {
                    System.out.println(name + "(" + type + "," + value + ")");
                }
                // 常量值错误，给出错误类型
                else {
                    System.out.println(name + "(" + errorInfo + ")");
                }
            }
            // 常量名定义错误
            else {
                System.out.println(name + "("
                        + "Wrong! It is not a identifier!" + ")");
            }
        }
        System.out.println("int_num=" + int_num + ";  char_num=" + char_num
                + ";  string_num=" + string_num + ";  float_num=" + float_num
                + ".");
    }
}

