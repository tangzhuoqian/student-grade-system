#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ѧ���ɼ���¼�ṹ
struct GradeRecord {
    string name;
    string studentId;
    string course;
    double score;
};

// ȫ�ֱ����洢���гɼ���¼
vector<GradeRecord> records;

// ��������
void addRecord();
void queryRecord();
void statistics();
void displayMenu();
bool isValidId(const string& id);
bool isValidScore(double score);

// ͳ�ƿγ̳ɼ�
/*void statistics() {
    cout << "\n===== ͳ�ƿγ̳ɼ� =====" << endl;
    string course;
    cout << "������γ����ƣ�";
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
        cout << "δ�ҵ��ÿγ̵ĳɼ���¼��" << endl;
        return;
    }
    
    cout << "�γ̣�" << course << endl;
    cout << "ƽ���֣�" << fixed << setprecision(2) << sum / count << endl;
    cout << "��߷֣�" << fixed << setprecision(1) << maxScore << endl;
    cout << "��ͷ֣�" << fixed << setprecision(1) << minScore << endl;
}
*/
int main() {
    int choice;
    do {
        displayMenu();
        cout << "������ѡ����ţ�";
        cin >> choice;
        cin.ignore(); // ������뻺�����Ļ��з�
        
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
                cout << "\n��лʹ��ѧ���ɼ�����ϵͳ���ټ���" << endl;
                return 0;
            default:
                cout << "������Ч��ѡ����������룡" << endl;
        }
    } while(true);
}

// ��ʾ�˵�
void displayMenu() {
    cout << "\n=================================" << endl;
    cout << "��ӭʹ��ѧ���ɼ�����ϵͳ" << endl;
    cout << "=================================" << endl;
    cout << "��ѡ�������" << endl;
    cout << "1. ��¼ѧ���ɼ�" << endl;
    cout << "2. ��ѯѧ���ɼ�" << endl;
    cout << "3. ͳ�ƿγ̳ɼ�" << endl;
    cout << "4. �˳�ϵͳ" << endl;
}

// ���ѧ���ɼ���¼
void addRecord() {
    cout << "\n===== ��¼ѧ���ɼ� =====" << endl;
    
    GradeRecord record;
    cout << "������ѧ��������";
    getline(cin, record.name);
    
    while(true) {
        cout << "������ѧ��ѧ�ţ�";
        getline(cin, record.studentId);
        
        if(isValidId(record.studentId)) {
            break;
        }
        cout << "���󣺸�ѧ���Ѵ��ڣ����������룡" << endl;
    }
    
    cout << "������γ����ƣ�";
    getline(cin, record.course);
    
    double score;
    while(true) {
        cout << "������ɼ���0-100����";
        cin >> score;
        cin.ignore(); // ������뻺�����Ļ��з�
        
        if(isValidScore(score)) {
            record.score = score;
            break;
        }
        cout << "���󣺳ɼ�������0-100֮�䣡" << endl;
    }
    
    records.push_back(record);
    cout << "�ɼ��ѳɹ���¼��" << endl;
}

// ��ѯѧ���ɼ�
void queryRecord() {
    cout << "\n===== ��ѯѧ���ɼ� =====" << endl;
    cout << "��ѡ���ѯ��ʽ��" << endl;
    cout << "1. ��ѧ��������ѯ" << endl;
    cout << "2. ��ѧ��ѧ�Ų�ѯ" << endl;
    cout << "3. ���γ����Ʋ�ѯ" << endl;
    
    int queryType;
    while(true) {
        cout << "������ѡ����ţ�";
        cin >> queryType;
        cin.ignore(); // ������뻺�����Ļ��з�
        
        if(queryType >= 1 && queryType <= 3) {
            break;
        }
        cout << "������������Ч��ѡ����ţ�1-3����" << endl;
    }
    
    string queryValue;
    cout << "�������ѯ���ݣ�";
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
            cout << "������" << record.name 
                 << ", ѧ�ţ�" << record.studentId
                 << ", �γ̣�" << record.course
                 << ", �ɼ���" << fixed << setprecision(1) << record.score << endl;
            found = true;
        }
    }
    
    if(!found) {
        cout << "δ�ҵ���ؼ�¼��" << endl;
    }
}

// ���ѧ���Ƿ��Ѵ���
bool isValidId(const string& id) {
    for(size_t i = 0; i < records.size(); i++) {
        const GradeRecord& record = records[i];
        if(record.studentId == id) {
            return false;
        }
    }
    return true;
}

// ���ɼ��Ƿ�����Ч��Χ��
bool isValidScore(double score) {
    return (score >= 0 && score <= 100);
}
