# include<bits/stdc++.h>

using namespace std;

class Marks{
    float cpp, dsa, de, ises, iscp, oe, average;
public:
    Marks() {
        cpp = 0;
        dsa = 0;
        de = 0;
        ises = 0;
        iscp = 0;
        oe = 0; 
        average = 0;
    }
    friend ofstream& operator <<(ofstream& sout, Marks &m);
    friend ostream& operator <<(ostream& sout, Marks &m);
    friend istream& operator >>(istream& sin, Marks &m);
    friend stringstream& operator>>(stringstream& ss, Marks&m);
    void setCPP(float m) {cpp = m;}
    void setDSA(float m) {dsa = m;}
    void setDE(float m) {de = m;}
    void setISES(float m) {ises = m;}
    void setISCP(float m) {iscp = m;}
    void setOE(float m) {oe = m;}

    float getCPP() {return cpp;}
    float getDSA() {return dsa;}
    float getDE() {return de;}
    float getISES() {return ises;}
    float getISCP() {return iscp;}
    float getOE() {return oe;}
    float getAvg() {return average;}

    void resetMarks() {cpp = 0; dsa = 0; de = 0; ises = 0; iscp = 0; oe = 0; average = 0;}
};

ofstream& operator <<(ofstream& sout, Marks &m) {
    sout << m.cpp << "," << m.dsa << "," << m.de << "," << m.ises << "," << m.iscp << "," << m.oe;
    return sout;
}
stringstream& operator>>(stringstream& ss, Marks&m) {
    string t;
    stringstream s;
    getline(ss, t, ',');
    s << t;
    s >> m.cpp;
    s.clear();
    getline(ss, t, ',');
    s << t;
    s >> m.dsa;
    s.clear();
    getline(ss, t, ',');
    s << t;
    s >> m.de;
    s.clear();
    getline(ss, t, ',');
    s << t;
    s >> m.ises;
    s.clear();
    getline(ss, t, ',');
    s << t;
    s >> m.iscp;
    s.clear();
    getline(ss, t);
    s << t;
    s >> m.oe;
    m.average = (m.cpp+m.dsa+m.de+m.ises+m.iscp+m.oe)/6;
    return ss;
}
ostream& operator <<(ostream& sout, Marks &m) {
    sout << "\t\t\t\tCPP: " << m.cpp << endl;
    sout << "\t\t\t\tDSA: " << m.dsa << endl;
    sout << "\t\t\t\tDE: " << m.de << endl;
    sout << "\t\t\t\tISES: " << m.ises << endl;
    sout << "\t\t\t\tISCP: " << m.iscp << endl;
    sout << "\t\t\t\tOE: " << m.oe << endl;
    sout << "\t\t\t\tOverall average: " << m.average << endl;
    return sout;
}
istream& operator >>(istream& sin, Marks &m) {
    cout << "\t\t\t\tEnter the Student Marks: " << endl;
    cout << "\t\t\t\tEnter CPP marks: ";
    sin >> m.cpp;
    cout << "\t\t\t\tEnter DSA marks: ";
    sin >> m.dsa;
    cout << "\t\t\t\tEnter DE marks: ";
    sin >> m.de;
    cout << "\t\t\t\tEnter ISES marks: ";
    sin >> m.ises;
    cout << "\t\t\t\tEnter ISCP marks: ";
    sin >> m.iscp;
    cout << "\t\t\t\tEnter OE marks: ";
    sin >> m.oe;
    m.average = m.cpp+m.dsa+m.de+m.ises+m.iscp+m.oe/6;
    return sin;
}

class Student{
    string name;
    string enrollment;
    string dob;
    string department;
    string section;
    int age;
    string address;
    Marks marks;
    static long long Enroll;
public:
    long long returnEnroll() {return Enroll;}
    string toString() {
        stringstream s;
        s << enrollment << "," << name << "," << dob << "," << department << "," << section << "," << age << "," << "\"" << address << "\"";
        return s.str();
    }
    friend ofstream& operator <<(ofstream& sout, Student &stu);
    friend ifstream& operator >>(ifstream& sin, Student &stu);
    friend ostream& operator <<(ostream& sout, Student &stu);
    friend istream& operator >>(istream& sin, Student &stu);
    string getEnrollment() {return enrollment;}
    string getDob() {return dob;}
    string getName() {return name;}
    string getDepartment() {return department;}
    string getSection() {return section;}
    int getAge() {return age;}
    string getAddress() {return address;}
    void setDob(string d) {dob = d;};
    void setDepartment(string dep) {department = dep;}
    void setSection(string sec) {section = sec;}
    void setAge(int a) {age = a;}
    void setAddress(string add) {address = add;}

    void setCPP(float m) {marks.setCPP(m);}
    void setDSA(float m) {marks.setDSA(m);}
    void setDE(float m) {marks.setDE(m);}
    void setISES(float m) {marks.setISES(m);}
    void setISCP(float m) {marks.setISCP(m);}
    void setOE(float m) {marks.setOE(m);}

    float getCPP() {return marks.getCPP();}
    float getDSA() {return marks.getDSA();}
    float getDE() {return marks.getDE();}
    float getISES() {return marks.getISES();}
    float getISCP() {return marks.getISCP();}
    float getOE() {return marks.getOE();}
    float getAvg() {return marks.getAvg();}

    void displayMarks() {cout << marks;}
    void resetMarks() {marks.resetMarks();}
};

long long getEnroll() {
    long long n;  
    ifstream fis;
    fis.open("temp.txt");
    fis >> n;
    fis.close();
    return n;
}

long long Student::Enroll = getEnroll();
Student s;
string file_name = "students.csv";
string f_name = "temp.csv";

void setEnroll() {
    ofstream fos;
    fos.open("temp.txt");
    fos << s.returnEnroll();
    fos.close();
}

ofstream& operator <<(ofstream& sout, Student &stu) {
    sout << stu.enrollment << "," << stu.name << "," << stu.dob << "," << stu.department << "," << stu.section << "," << "\"" << stu.address << "\"" << ",";
    sout << stu.marks << endl;
    return sout;
}
ifstream& operator >>(ifstream& sin, Student &stu) {
    string t;
    getline(sin >> ws, t);
    stringstream s(t);
    string a[6];
    for(int i=0; i<6; i++) {
        if(i!=5) {
            getline(s, a[i], ',');
        }
        else {
            stringstream ss;
            getline(s, t, '\"');
            getline(s, a[i], '\"');
            getline(s, t, ',');
            getline(s, t, ',');
            ss << t;
            ss >> stu.age;
            s >> stu.marks;
        }
    }
    stu.enrollment = a[0];
    stu.name = a[1];
    stu.dob = a[2];
    stu.department = a[3];
    stu.section = a[4];
    stu.address = a[5];
    return sin;
}


ostream& operator <<(ostream& sout, Student &stu) {
    sout << "\t\t\t\tStudent Details: " << endl;
    sout << "\t\t\t\tName of the student: " << stu.name << endl;
    sout << "\t\t\t\tEnrollment Number: " << stu.enrollment << endl;
    sout << "\t\t\t\tDate of Birth: " << stu.dob << endl;
    sout << "\t\t\t\tAge: " << stu.age << endl;
    sout << "\t\t\t\tDepartment: " << stu.department << endl;
    sout << "\t\t\t\tSection: " << stu.section << endl;
    sout << "\t\t\t\tAddress: " << stu.address << endl;
    sout << stu.marks;
    return sout;
}
istream& operator >>(istream& sin, Student &stu) {
    cout << "\t\t\t\tEnter Student's Name: ";
    getline(sin >> ws, stu.name);
    cout << "\t\t\t\tEnter Date of Birth of student (dd-mm-yyyy): ";
    sin >> stu.dob;
    cout << "\t\t\t\tEnter Age of Student: ";
    sin >> stu.age;
    cout << "\t\t\t\tEnter the Department: ";
    sin >> stu.department;
    cout << "\t\t\t\tEnter the section: ";
    sin >> stu.section;
    cout << "\t\t\t\tEnter Address: ";
    getline(sin >> ws, stu.address);
    stringstream t;
    t << "AP" << stu.Enroll;
    stu.enrollment = t.str();
    stu.Enroll++;
    return sin;
}

void enroll() {
    ofstream fout;
    fout.open(file_name, ios::app);
    cin >> s;
    s.resetMarks();
    fout << s;
    fout.close();
    cout << "\t\t\t\tStudent Has been Successfully enrolled, your enrollment number is: " << s.getEnrollment() << endl << endl;
    setEnroll();
    cout << "\t\t\t\tPress Enter to Continue...";
    cin.get();
}

void unenroll() {
    ofstream fout;
    ifstream fin;
    string id;
    bool f = false;
    fout.open(f_name);
    fin.open(file_name);
    cout << "\t\t\t\tEnter the enrollment number of the student you want to unenroll: ";
    cin >> id;
    while(fin >> s) {
        if(s.getEnrollment() != id) {
            fout << s;
        }
        else {
            f = true;
        }
    }
    fout.close();
    fin.close();
    if(remove(file_name.c_str())) {
        cout << "\t\t\t\tError removing the temporary file!" << endl;
    }
    if(rename(f_name.c_str(), file_name.c_str())) {
        cout << "\t\t\t\tError renaming the file!" << endl;
    }
    if(!f) {
        cout << "\t\t\t\tStudent not found!" << endl;
    }
    else {
    	cout << "\t\t\t\tStudent Unenrolled Successfully." << endl;
	}
	cout << "\t\t\t\tPress Enter to Continue...";
    cin.get();
}

void edit_personal() {
    ifstream fis;
    ofstream fos;
    string id;
    bool f = false;
    fis.open(file_name);
    fos.open(f_name);
    cout << "\t\t\t\tEnter the enrollment number of the student you want to Edit: ";
    cin >> id;
    while(fis >> s) {
        if(s.getEnrollment() == id) {
            f = true;
            char choice;
            string t;
            cout << "\t\t\t\tWould you like to change DOB?(y/n): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                cout << "\t\t\t\tEnter the DOB of the student: ";
                getline(cin >> ws, t);
                s.setDob(t);
            }
            cout << "\t\t\t\tWould you like to change Department?(y/n): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                cout << "\t\t\t\tEnter the department of the student: ";
                getline(cin >> ws, t);
                s.setDepartment(t);
            }
            cout << "\t\t\t\tWould you like to change section?(y/n): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                cout << "\t\t\t\tEnter the section of the student: ";
                getline(cin >> ws, t);
                s.setSection(t);
            }
            cout << "\t\t\t\tWould you like to change Address?(y/n): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                cout << "\t\t\t\tEnter the Address of the student: ";
                getline(cin >> ws, t);
                s.setAddress(t);
            }
            cout << "\t\t\t\tWould you like to Age dob?(y/n): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                cout << "\t\t\t\tEnter the Age of the student: ";
                cin >> choice;
                s.setAge(choice);
            }
        }
        fos << s;
    }
    fos.close();
    fis.close();
    if(remove(file_name.c_str())) {
        cout << "\t\t\t\tError removing the temporary file!" << endl;
    }
    if(rename(f_name.c_str(), file_name.c_str())) {
        cout << "\t\t\t\tError renaming the file!" << endl;
    }
    if(!f) {
        cout << "\t\t\t\tStudent not found!" << endl;
    }
    cout << "\t\t\t\tPress Enter to Continue...";
    cin.get();
}

void edit_Marks() {
    ifstream fis;
    ofstream fos;
    string id;
    bool f = false;
    fis.open(file_name);
    fos.open(f_name);
    cout << "\t\t\t\tEnter the enrollment number of the student you want to Edit: ";
    cin >> id;
    while(fis >> s) {
        if(s.getEnrollment() == id) {
            f = true;
            float choice;
            char c;
            cout << "\t\t\t\tWould you like to change CPP Marks?(y/n): ";
            cin >> c;
            if(c == 'y' || c == 'Y'){
                cin.ignore();
                cout << "\t\t\t\tEnter the CPP marks of the student: ";
                cin >> choice;
                s.setCPP(choice);
            }
            cout << "\t\t\t\tWould you like to change DSA Marks?(y/n): ";
            cin >> c;
            if(c == 'y' || c == 'Y'){
                cin.ignore();
                cout << "\t\t\t\tEnter the DSA marks of the student: ";
                cin >> choice;
                s.setDSA(choice);
            }
            cout << "\t\t\t\tWould you like to change DE Marks?(y/n): ";
            cin >> c;
            if(c == 'y' || c == 'Y'){
                cin.ignore();
                cout << "\t\t\t\tEnter the DE marks of the student: ";
                cin >> choice;
                s.setDE(choice);
            }
            cout << "\t\t\t\tWould you like to change ISES Marks?(y/n): ";
            cin >> c;
            if(c == 'y' || c == 'Y'){
                cin.ignore();
                cout << "\t\t\t\tEnter the ISES marks of the student: ";
                cin >> choice;
                s.setISES(choice);
            }
            cout << "\t\t\t\tWould you like to change ISCP Marks?(y/n): ";
            cin >> c;
            if(c == 'y' || c == 'Y'){
                cin.ignore();
                cout << "\t\t\t\tEnter the ISCP marks of the student: ";
                cin >> choice;
                s.setISCP(choice);
            }
            cout << "\t\t\t\tWould you like to change OE Marks?(y/n): ";
            cin >> c;
            if(c == 'y' || c == 'Y'){
                cin.ignore();
                cout << "\t\t\t\tEnter the OE marks of the student: ";
                cin >> choice;
                s.setOE(choice);
            }
        }
        fos << s;
    }
    fos.close();
    fis.close();
    if(remove(file_name.c_str())) {
        cout << "\t\t\t\tError removing the temporary file!" << endl;
    }
    if(rename(f_name.c_str(), file_name.c_str())) {
        cout << "\t\t\t\tError renaming the file!" << endl;
    }
    if(!f) {
        cout << "\t\t\t\tStudent not found!" << endl;
    }
    cout << "\t\t\t\tPress Enter to Continue...";
    cin.ignore();
    cin.get();
}

void edit() {
    int choice;
    cout << "\t\t\t\t1)To Edit Personal Details" << endl;
    cout << "\t\t\t\t2)To Edit Student Marks" << endl;
    cout << "\t\t\t\t3)To Cancel" << endl;
    cout << "\t\t\t\tEnter your choice: ";
    cin >> choice;
    while(choice > 3 || choice < 1) {
        cout << "\t\t\t\tEnter a valid choice!: " << endl;
        cin >> choice;
    }
    switch(choice) {
            case 1: edit_personal();
                    break;
            case 2: edit_Marks();
                    break;
            case 3: return;
    }
}

void search() {
    ifstream fin;
    string id;
    bool f = false;
    fin.open(file_name);
    cout << "\t\t\t\tEnter the enrollment number of the student you want to Search: ";
    cin >> id;
    while(fin >> s) {
        if(s.getEnrollment() == id) {
            f = true;
            break;
        }
    }
    fin.close();
    if(f) {
        cout << s;
    }
    cout << "\t\t\t\tPress Enter to Continue...";
    cin.ignore();
    cin.get();
}

void add_marks() {
    ofstream fos;
    ifstream fin;
    fin.open(file_name);
    fos.open(f_name);
    float m;
    cout << "\t\t\t\tEnter the Marks of every student: " << endl;
    while(fin >> s) {
        cout << "\t\t\t\tEnter the Marks of enrollment Number " << s.getEnrollment() << ": " << endl;
        cout << "\t\t\t\tEnter the CPP marks: ";
        cin >> m;
        s.setCPP(m);
        cout << "\t\t\t\tEnter the DSA marks: ";
        cin >> m;
        s.setDSA(m);
        cout << "\t\t\t\tEnter the DE marks: ";
        cin >> m;
        s.setDE(m);
        cout << "\t\t\t\tEnter the ISES marks: ";
        cin >> m;
        s.setISES(m);
        cout << "\t\t\t\tEnter the ISCP marks: ";
        cin >> m;
        s.setISCP(m);
        cout << "\t\t\t\tEnter the OE marks: ";
        cin >> m;
        s.setOE(m);

        fos << s;
    }
    fos.close();
    fin.close();
    if(remove(file_name.c_str())) {
        cout << "\t\t\t\tError removing the temporary file!" << endl;
    }
    if(rename(f_name.c_str(), file_name.c_str())) {
        cout << "\t\t\t\tError renaming the file!" << endl;
    }
    cout << "\t\t\t\tPress Enter to Continue...";
    cin.get();
}

void display_marks() {
    ifstream fin;
    string id;
    bool f = false;
    fin.open(file_name);
    cout << "\t\t\t\tEnter the enrollment number of the student you want marks for: ";
    cin >> id;
    while(fin >> s) {
        if(s.getEnrollment() == id) {
            f = true;
            break;
        }
    }
    fin.close();
    if(f) {
        cout << "\t\t\t\tMarks of " << s.getEnrollment() << ": " << endl;
        s.displayMarks();
    }
    cout << "\t\t\t\tPress Enter to Continue...";
    cin.get();
}

void display_every_record() {
    ifstream fis;
    fis.open(file_name);
    bool e = false;
    cout << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t      NAME       |  Enrollment  | CPP | DSA | DE  | ISES | ISCP | OE  | Avg      " << endl; 
    cout << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
    while(fis >> s) {
        e = true;
        cout << "\t\t\t\t" << left << setw(18) << s.getName() << setw(16) << s.getEnrollment() << setw(6) << s.getCPP() << setw(6) << s.getDSA() << setw(7) << s.getDE() << setw(6) << s.getISES() << setw(7) << s.getISCP() << setw(6) << s.getOE() << setw(6) << s.getAvg() << endl;
    }
    if(!e) {
        cout << "\t\t\t\tThere is no student in the record!" << endl;
    }
    cout << endl << endl;
    fis.close();
    cout << "\t\t\t\tPress Enter to Continue...";
    cin.get();
}

int main() {
    // add, delete, edit, search, add marks, display marks;
    int choice = 0;
    while(choice != 8) {
        system("cls");
        cout << "\t\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t-------------------- Student Record Management -------------------" << endl;
        cout << "\t\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t1) To enroll a student" << endl;
        cout << "\t\t\t\t2) To unenroll a student" << endl;
        cout << "\t\t\t\t3) To edit a student's details" << endl;
        cout << "\t\t\t\t4) To search a student's record" << endl;
        cout << "\t\t\t\t5) To add marks" << endl;
        cout << "\t\t\t\t6) To display marks" << endl;
        cout << "\t\t\t\t7) To display every students marks" << endl;
        cout << "\t\t\t\t8) To Exit" << endl;
        cout << "\t\t\t\tEnter your choice: ";
        cin >> choice;
        system("cls");
        switch(choice) {
            case 1: enroll();
                    break;
            case 2: unenroll();
                    break;
            case 3: edit();
                    break;
            case 4: search();
                    break;
            case 5: add_marks();
                    break;
            case 6: display_marks();
                    break;
            case 7: display_every_record();
                    break;
            case 8: break;
            default:cout << "Enter a valid choice!" << endl;
            system("clear");
        }
    }
    return 0;
}
