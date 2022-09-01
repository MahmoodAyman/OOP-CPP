#include<bits/stdc++.h>
using namespace std;
struct exam {
	double first_exam, second_exam, final_exam;
};
class subject {
private:
	string name;
	exam x;
public:
	subject() {
		name = "subject";
		x.first_exam = 0;
		x.second_exam = 0;
		x.final_exam = 0;
	}
	subject(string n,double first, double second, double final) {
		name = n;
		x = { first,second,final }; // first_exam , second_exam, final_exam
	}
	void set_name(string name) {
		this->name = name;
	}
	void set_results(exam x) {
		this->x = x;
	}
	double total_result() {
		return x.first_exam + x.second_exam + x.final_exam;
	}
	double get_first() {
		return x.first_exam;
	}
	double get_second() {
		return x.second_exam;
	}
	double get_final() {
		return x.final_exam;
	}
	void print() {
		cout << "subject Name is: " << name << endl;
		cout << "first Exam result = " << x.first_exam << endl;
		cout << "and second exam result = " << x.second_exam << endl;
		cout << " and the final exam results = " << x.final_exam << endl;
		cout << "total_result = " << total_result() << endl;
	}
};
class student{
private:
	string name, id;
	subject s[10];
public:
	student() {
		name = "no name";
		id = "0";
		for (int i = 0; i < 10; i++) {
			s[i].set_name("no name");
			s[i].set_results({ 0,0,0 });
		}
	}
	student(string n, string i) {
		name = n;
		id = i;
	}
	void set_name(string n) {
		name = n;
	}
	void set_id(string id) {
		this->id = id;
	}
	void set_subjects(int i, exam e) {
				string n;
				s[i].set_name(n);
				s[i].set_results(e);
		
	}
	subject get_subject(int x) {
		return s[x];
	}
	double total(int x) {
		return s[x].total_result();
	}
	string get_name(){
		return name;
	}
	string get_id() {
		return id;
	}
	void print();
};
void student::print() {
	cout << "student Name is: " << this->name << endl;
	cout << "He got in first subject " << total(0) << endl;
	cout << "results in brief are" << endl;
	cout << "first exam = " << get_subject(0).get_first() << endl;
	cout << "second exam = " << get_subject(0).get_second() << endl;
	cout << "final exam = " << get_subject(0).get_final() << endl;
}
int main() {
	student s;
	s.set_name("Mahmoud");
	s.set_id("12345");
	cout << "Enter Number of Subjects" << endl;
	int n; cin >> n;
	if (n >= 10)return cout << "Error" << endl,0;
	for (int i = 0; i < n; i++) {
		double first, second, final;
		cout << "Enter first Exam result: ";
		cin >> first;
		cout << "Enter seocond Exam result: ";
		cin >> second;
		cout << "Enter final Exam result: ";
		cin >> final;
		s.set_subjects(i, { first,second,final });
	}
	s.print();
}
