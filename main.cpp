#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// 学生成绩记录结构
struct GradeRecord {
    string name;
    string studentId;
    string course;
    double score;
};

// 全局变量存储所有成绩记录
vector<GradeRecord> records;

// 函数声明
void addRecord();
void queryRecord();
void statistics();
void displayMenu();
bool isValidId(const string& id);
bool isValidScore(double score);

// 统计课程成绩
/*void statistics() {
    cout << "\n===== 统计课程成绩 =====" << endl;
    string course;
    cout << "请输入课程名称：";
    getline(cin, course);
    
    double sum = 0;
    double maxScore = -1;
    double minScore = 101;
    int count = 0;
    
    for(size_t i = 0; i < records.size(); i++) {
        const GradeRecord& record = records[i];
        if(record.course == course) {
            sum += record.score;
            if(record.score > maxScore) maxScore = record.score;
            if(record.score < minScore) minScore = record.score;
            count++;
        }
    }
    
    if(count == 0) {
        cout << "未找到该课程的成绩记录！" << endl;
        return;
    }
    
    cout << "课程：" << course << endl;
    cout << "平均分：" << fixed << setprecision(2) << sum / count << endl;
    cout << "最高分：" << fixed << setprecision(1) << maxScore << endl;
    cout << "最低分：" << fixed << setprecision(1) << minScore << endl;
}
*/
int main() {
    int choice;
    do {
        displayMenu();
        cout << "请输入选项序号：";
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区的换行符
        
        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                queryRecord();
                break;
            /*case 3:
                statistics();
                break;*/
            case 4:
                cout << "\n感谢使用学生成绩管理系统，再见！" << endl;
                return 0;
            default:
                cout << "错误：无效的选项，请重新输入！" << endl;
        }
    } while(true);
}

// 显示菜单
void displayMenu() {
    cout << "\n=================================" << endl;
    cout << "欢迎使用学生成绩管理系统" << endl;
    cout << "=================================" << endl;
    cout << "请选择操作：" << endl;
    cout << "1. 记录学生成绩" << endl;
    cout << "2. 查询学生成绩" << endl;
    cout << "3. 统计课程成绩" << endl;
    cout << "4. 退出系统" << endl;
}

// 添加学生成绩记录
void addRecord() {
    cout << "\n===== 记录学生成绩 =====" << endl;
    
    GradeRecord record;
    cout << "请输入学生姓名：";
    getline(cin, record.name);
    
    while(true) {
        cout << "请输入学生学号：";
        getline(cin, record.studentId);
        
        if(isValidId(record.studentId)) {
            break;
        }
        cout << "错误：该学号已存在，请重新输入！" << endl;
    }
    
    cout << "请输入课程名称：";
    getline(cin, record.course);
    
    double score;
    while(true) {
        cout << "请输入成绩（0-100）：";
        cin >> score;
        cin.ignore(); // 清除输入缓冲区的换行符
        
        if(isValidScore(score)) {
            record.score = score;
            break;
        }
        cout << "错误：成绩必须在0-100之间！" << endl;
    }
    
    records.push_back(record);
    cout << "成绩已成功记录！" << endl;
}

// 查询学生成绩
void queryRecord() {
    cout << "\n===== 查询学生成绩 =====" << endl;
    cout << "请选择查询方式：" << endl;
    cout << "1. 按学生姓名查询" << endl;
    cout << "2. 按学生学号查询" << endl;
    cout << "3. 按课程名称查询" << endl;
    
    int queryType;
    while(true) {
        cout << "请输入选项序号：";
        cin >> queryType;
        cin.ignore(); // 清除输入缓冲区的换行符
        
        if(queryType >= 1 && queryType <= 3) {
            break;
        }
        cout << "错误：请输入有效的选项序号（1-3）！" << endl;
    }
    
    string queryValue;
    cout << "请输入查询内容：";
    getline(cin, queryValue);
    
    bool found = false;
    for(size_t i = 0; i < records.size(); i++) {
        const GradeRecord& record = records[i];
        bool match = false;
        switch(queryType) {
            case 1: match = (record.name == queryValue); break;
            case 2: match = (record.studentId == queryValue); break;
            case 3: match = (record.course == queryValue); break;
        }
        
        if(match) {
            cout << "姓名：" << record.name 
                 << ", 学号：" << record.studentId
                 << ", 课程：" << record.course
                 << ", 成绩：" << fixed << setprecision(1) << record.score << endl;
            found = true;
        }
    }
    
    if(!found) {
        cout << "未找到相关记录！" << endl;
    }
}

// 检查学号是否已存在
bool isValidId(const string& id) {
    for(size_t i = 0; i < records.size(); i++) {
        const GradeRecord& record = records[i];
        if(record.studentId == id) {
            return false;
        }
    }
    return true;
}

// 检查成绩是否在有效范围内
bool isValidScore(double score) {
    return (score >= 0 && score <= 100);
}
