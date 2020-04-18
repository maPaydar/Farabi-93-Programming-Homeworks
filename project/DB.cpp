
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student
{
	int id;
	string name;
	string family;
	string national_id;
	int entrance_year;
	float math_grade;
	float physics_grade;
	float literature_grade;
	float c_grade;
};
struct professor
{
	int id;
	string name;
	string family;
	string national_id;
	int employ_year;
	string group_name;
	string degree;
	string academic_rank;
	int salary;
};
struct employee
{
	int id;
	string name;
	string family;
	string national_id;
	int employ_year;
	string group_name;
	int salary;
};
void init();

bool insert_std(student insert);
bool insert_prof(professor insert);
bool insert_empl(employee insert);

student* select_std(int ID);
professor* select_prof(int ID);
employee* select_empl(int ID);

bool delete_std(int ID);
bool delete_prof(int ID);
bool delete_empl(int ID);

bool update_std(int ID, float math, float physics, float adab, float c);
bool update_prof(int ID, int salary);
bool update_empl(int ID, int salary);

bool update_std_adv(student update);
bool update_prof_adv(professor update);
bool update_emp_adv(employee update);

student* select_std_adv(student insert);
professor* select_prof_adv(professor insert);
employee* select_emp_adv(employee insert);

int main()
{
    
}

void init()
{}
bool insert_std(student insert)
{
	ifstream fin;
	ofstream fout;
	fin.open("Students Information.txt");
	fout.open("Students Information.txt", ios::app);
	student temp;
	bool existStd = true;
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.entrance_year >> temp.math_grade >> temp.physics_grade >> temp.literature_grade >> temp.c_grade)
	{
		if (temp.id == insert.id)
		{
			existStd = false;
			return false;
		}
	}
	if (existStd == true)
	{
		if (insert.name == "")
			insert.name = "----";
		if (insert.family == "")
			insert.family = "----";
		if (insert.national_id == "")
			insert.national_id = "----";
		fout << insert.id << endl;
		fout << insert.name << endl;
		fout << insert.family << endl;
		fout << insert.national_id << endl;
		fout << insert.entrance_year << endl;
		fout << insert.math_grade << endl;
		fout << insert.physics_grade << endl;
		fout << insert.literature_grade << endl;
		fout << insert.c_grade << endl;
		return true;
	}

}
bool insert_prof(professor insert)
{
	ifstream fin;
	ofstream fout;
	fin.open("Professor Information.txt");
	fout.open("Professor Information.txt", ios::app);
	professor temp;
	bool existProf = true;
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.degree >> temp.academic_rank >> temp.salary)
	{
		if (temp.id == insert.id)
		{
			existProf = false;
			return false;
		}
	}
	if (existProf == true)
	{
		if (insert.name == "")
			insert.name = "----";
		if (insert.family == "")
			insert.family = "----";
		if (insert.national_id == "")
			insert.national_id = "----";
		if (insert.group_name == "")
			insert.group_name = "----";
		if (insert.degree == "")
			insert.degree = "----";
		if (insert.academic_rank == "")
			insert.academic_rank = "----";
		fout << insert.id << endl;
		fout << insert.name << endl;
		fout << insert.family << endl;
		fout << insert.national_id << endl;
		fout << insert.employ_year << endl;
		fout << insert.group_name << endl;
		fout << insert.degree << endl;
		fout << insert.academic_rank << endl;
		fout << insert.salary << endl;
		return true;
	}
}
bool insert_empl(employee insert)
{
	ifstream fin;
	ofstream fout;
	fin.open("Employee Information.txt");
	fout.open("Employee Information.txt", ios::app);
	employee temp;
	bool existEmpl = true;
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.salary)
	{
		if (temp.id == insert.id)
		{
			existEmpl = false;
			return false;
		}
	}
	if (existEmpl == true)
	{
		if (insert.name == "")
			insert.name = "----";
		if (insert.family == "")
			insert.family = "----";
		if (insert.national_id == "")
			insert.national_id = "----";
		if (insert.group_name == "")
			insert.group_name = "----";
		fout << insert.id << endl;
		fout << insert.name << endl;
		fout << insert.family << endl;
		fout << insert.national_id << endl;
		fout << insert.employ_year << endl;
		fout << insert.group_name << endl;
		fout << insert.salary << endl;
		return true;
	}
}

student* select_std(int ID)
{
	student temp;
	student* select = new student;
	bool existStd = false;
	ifstream fin;
	fin.open("Students Information.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.entrance_year >> temp.math_grade >> temp.physics_grade >> temp.literature_grade >> temp.c_grade)
	{
		if (temp.id == ID)
		{
			existStd = true;
			(*select).id = temp.id;
			(*select).name = temp.name;
			(*select).family = temp.family;
			(*select).national_id = temp.national_id;
			(*select).entrance_year = temp.entrance_year;
			(*select).math_grade = temp.math_grade;
			(*select).physics_grade = temp.physics_grade;
			(*select).literature_grade = temp.literature_grade;
			(*select).c_grade = temp.c_grade;
			if ((*select).name == "----")
				(*select).name = "";
			if ((*select).family == "----")
				(*select).family = "";
			if ((*select).national_id == "----")
				(*select).national_id = "";

		}
	}
	return select;
}
professor* select_prof(int ID)
{
	professor temp;
	professor* select = new professor;
	bool existProf = false;
	ifstream fin;
	fin.open("Professor Information.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.degree >> temp.academic_rank >> temp.salary)
	{
		if (temp.id == ID)
		{
			existProf = true;
			(*select).id = temp.id;
			(*select).name = temp.name;
			(*select).family = temp.family;
			(*select).national_id = temp.national_id;
			(*select).employ_year = temp.employ_year;
			(*select).group_name = temp.group_name;
			(*select).degree = temp.degree;
			(*select).academic_rank = temp.academic_rank;
			(*select).salary = temp.salary;
			if ((*select).name == "----")
				(*select).name = "";
			if ((*select).family == "----")
				(*select).family = "";
			if ((*select).national_id == "----")
				(*select).national_id = "";
			if ((*select).group_name == "----")
				(*select).group_name = "";
			if ((*select).degree == "----")
				(*select).degree = "";
			if ((*select).academic_rank == "----")
				(*select).academic_rank = "";
		}
	}
	return select;
}
employee* select_empl(int ID)
{
	employee temp;
	employee* select = new employee;
	bool existEmpl = false;
	ifstream fin;
	fin.open("Employee Information.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.salary)
	{
		if (temp.id == ID)
		{
			existEmpl = true;
			(*select).id = temp.id;
			(*select).name = temp.name;
			(*select).family = temp.family;
			(*select).national_id = temp.national_id;
			(*select).employ_year = temp.employ_year;
			(*select).group_name = temp.group_name;
			(*select).salary = temp.salary;
			if ((*select).name == "----")
				(*select).name = "";
			if ((*select).family == "----")
				(*select).family = "";
			if ((*select).national_id == "----")
				(*select).national_id = "";
			if ((*select).group_name == "----")
				(*select).group_name = "";
		}
	}
	return select;
}

bool delete_std(int ID)
{
	bool dlt = false;
	student temp;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Students Information.txt");
	fout2.open("TempDelete.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.entrance_year >> temp.math_grade >> temp.physics_grade >> temp.literature_grade >> temp.c_grade)
	{
		if (temp.id == ID)
			dlt = true;
		else
		{
			fout2 << temp.id << endl;
			fout2 << temp.name << endl;
			fout2 << temp.family << endl;
			fout2 << temp.national_id << endl;
			fout2 << temp.entrance_year << endl;
			fout2 << temp.math_grade << endl;
			fout2 << temp.physics_grade << endl;
			fout2 << temp.literature_grade << endl;
			fout2 << temp.c_grade << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempDelete.txt");
	fout.open("Students Information.txt");
	while (fin2 >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.entrance_year >> temp.math_grade >> temp.physics_grade >> temp.literature_grade >> temp.c_grade)
	{
		fout << temp.id << endl;
		fout << temp.name << endl;
		fout << temp.family << endl;
		fout << temp.national_id << endl;
		fout << temp.entrance_year << endl;
		fout << temp.math_grade << endl;
		fout << temp.physics_grade << endl;
		fout << temp.literature_grade << endl;
		fout << temp.c_grade << endl;
	}
	return dlt;
}
bool delete_prof(int ID)
{
	bool dlt = false;
	professor temp;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Professor Information.txt");
	fout2.open("TempDelete.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.degree >> temp.academic_rank >> temp.salary)
	{
		if (temp.id == ID)
			dlt = true;
		else
		{
			fout2 << temp.id << endl;
			fout2 << temp.name << endl;
			fout2 << temp.family << endl;
			fout2 << temp.national_id << endl;
			fout2 << temp.employ_year << endl;
			fout2 << temp.group_name << endl;
			fout2 << temp.degree << endl;
			fout2 << temp.academic_rank << endl;
			fout2 << temp.salary << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempDelete.txt");
	fout.open("Professor Information.txt");
	while (fin2 >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.degree >> temp.academic_rank >> temp.salary)
	{
		fout << temp.id << endl;
		fout << temp.name << endl;
		fout << temp.family << endl;
		fout << temp.national_id << endl;
		fout << temp.employ_year << endl;
		fout << temp.group_name << endl;
		fout << temp.degree << endl;
		fout << temp.academic_rank << endl;
		fout << temp.salary << endl;
	}
	return dlt;
}
bool delete_empl(int ID)
{
	bool dlt = false;
	employee temp;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Employee Information.txt");
	fout2.open("TempDelete.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.salary)
	{
		if (temp.id == ID)
			dlt = true;
		else
		{
			fout2 << temp.id << endl;
			fout2 << temp.name << endl;
			fout2 << temp.family << endl;
			fout2 << temp.national_id << endl;
			fout2 << temp.employ_year << endl;
			fout2 << temp.group_name << endl;
			fout2 << temp.salary << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempDelete.txt");
	fout.open("Employee Information.txt");
	while (fin2 >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.salary)
	{
		fout << temp.id << endl;
		fout << temp.name << endl;
		fout << temp.family << endl;
		fout << temp.national_id << endl;
		fout << temp.employ_year << endl;
		fout << temp.group_name << endl;
		fout << temp.salary << endl;
	}
	return dlt;
}

bool update_std(int ID, float math, float physics, float adab, float c)
{
	bool update = false;
	student up;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Students Information.txt");
	fout2.open("TempStd.txt");
	while (fin >> up.id >> up.name >> up.family >> up.national_id >> up.entrance_year >> up.math_grade >> up.physics_grade >> up.literature_grade >> up.c_grade)
	{
		if (up.id == ID)
		{
			update = true;
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.entrance_year << endl;
			fout2 << math << endl;
			fout2 << physics << endl;
			fout2 << adab << endl;
			fout2 << c << endl;
		}
		else
		{
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.entrance_year << endl;
			fout2 << up.math_grade << endl;
			fout2 << up.physics_grade << endl;
			fout2 << up.literature_grade << endl;
			fout2 << up.c_grade << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempStd.txt");
	fout.open("Students Information.txt");
	while (fin2 >> up.id
		   >> up.name
		   >> up.family
		   >> up.national_id
		   >> up.entrance_year
		   >> up.math_grade
		   >> up.physics_grade
		   >> up.literature_grade
		   >> up.c_grade)
	{
		fout << up.id << endl;
		fout << up.name << endl;
		fout << up.family << endl;
		fout << up.national_id << endl;
		fout << up.entrance_year << endl;
		fout << up.math_grade << endl;
		fout << up.physics_grade << endl;
		fout << up.literature_grade << endl;
		fout << up.c_grade << endl;
	}
	return update;
}
bool update_prof(int ID, int salary)
{
	bool update = false;
	professor up;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Professor Information.txt");
	fout2.open("TempProf.txt");
	while (fin >> up.id >> up.name >> up.family >> up.national_id >> up.employ_year >> up.group_name >> up.degree >> up.academic_rank >> up.salary)
	{
		if (up.id == ID)
		{
			update = true;
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.employ_year << endl;
			fout2 << up.group_name << endl;
			fout2 << up.degree << endl;
			fout2 << up.academic_rank << endl;
			fout2 << salary << endl;
		}
		else
		{
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.employ_year << endl;
			fout2 << up.group_name << endl;
			fout2 << up.degree << endl;
			fout2 << up.academic_rank << endl;
			fout2 << up.salary << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempProf.txt");
	fout.open("Professor Information.txt");
	while (fin2 >> up.id >> up.name >> up.family >> up.national_id >> up.employ_year >> up.group_name >> up.degree >> up.academic_rank >> up.salary)
	{
		fout << up.id << endl;
		fout << up.name << endl;
		fout << up.family << endl;
		fout << up.national_id << endl;
		fout << up.employ_year << endl;
		fout << up.group_name << endl;
		fout << up.degree << endl;
		fout << up.academic_rank << endl;
		fout << up.salary << endl;
	}
	return update;
}
bool update_empl(int ID, int salary)
{
	bool update = false;
	employee up;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Employee Information.txt");
	fout2.open("TempEmpl.txt");
	while (fin >> up.id >> up.name >> up.family >> up.national_id >> up.employ_year >> up.group_name >> up.salary)
	{
		if (up.id == ID)
		{
			update = true;
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.employ_year << endl;
			fout2 << up.group_name << endl;
			fout2 << salary << endl;
		}
		else
		{
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.employ_year << endl;
			fout2 << up.group_name << endl;
			fout2 << up.salary << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempEmpl.txt");
	fout.open("Employee Information.txt");
	while (fin2 >> up.id >> up.name >> up.family >> up.national_id >> up.employ_year >> up.group_name >> up.salary)
	{
		fout << up.id << endl;
		fout << up.name << endl;
		fout << up.family << endl;
		fout << up.national_id << endl;
		fout << up.employ_year << endl;
		fout << up.group_name << endl;
		fout << up.salary << endl;
	}
	return update;
}

bool update_std_adv(student update)
{
	bool upd = false;
	student up;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Students Information.txt");
	fout2.open("TempStd.txt");
	while (fin >> up.id >> up.name >> up.family >> up.national_id >> up.entrance_year >> up.math_grade >> up.physics_grade >> up.literature_grade >> up.c_grade)
	{
		if (up.id == update.id)
		{
			upd = true;
			fout2 << up.id << endl;
			if (update.name != "")
				fout2 << update.name << endl;
			else
				fout2 << up.name << endl;
			if (update.family != "")
				fout2 << update.family << endl;
			else
				fout2 << up.family << endl;
			if (update.national_id != "")
				fout2 << update.national_id << endl;
			else
				fout2 << up.national_id << endl;
			if (update.entrance_year != 0)
				fout2 << update.entrance_year << endl;
			else
				fout2 << up.entrance_year << endl;
			if (update.math_grade != 0)
				fout2 << update.math_grade << endl;
			else
				fout2 << up.math_grade << endl;
			if (update.physics_grade != 0)
				fout2 << update.physics_grade << endl;
			else
				fout2 << up.physics_grade << endl;
			if (update.literature_grade != 0)
				fout2 << update.literature_grade << endl;
			else
				fout2 << up.literature_grade << endl;
			if (update.c_grade != 0)
				fout2 << update.c_grade << endl;
			else
				fout2 << up.c_grade << endl;
		}
		else
		{
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.entrance_year << endl;
			fout2 << up.math_grade << endl;
			fout2 << up.physics_grade << endl;
			fout2 << up.literature_grade << endl;
			fout2 << up.c_grade << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempStd.txt");
	fout.open("Students Information.txt");
	while (fin2 >> up.id >> up.name >> up.family >> up.national_id >> up.entrance_year >> up.math_grade >> up.physics_grade >> up.literature_grade >> up.c_grade)
	{
		fout << up.id << endl;
		fout << up.name << endl;
		fout << up.family << endl;
		fout << up.national_id << endl;
		fout << up.entrance_year << endl;
		fout << up.math_grade << endl;
		fout << up.physics_grade << endl;
		fout << up.literature_grade << endl;
		fout << up.c_grade << endl;
	}
	return upd;
}
bool update_prof_adv(professor update)
{
	bool upd = false;
	professor up;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Professor Information.txt");
	fout2.open("TempProf.txt");
	while (fin >> up.id >> up.name >> up.family >> up.national_id >> up.employ_year >> up.group_name >> up.degree >> up.academic_rank >> up.salary)
	{
		if (up.id == update.id)
		{
			upd = true;
			fout2 << up.id << endl;
			if (update.name != "")
				fout2 << update.name << endl;
			else
				fout2 << up.name << endl;
			if (update.family != "")
				fout2 << update.family << endl;
			else
				fout2 << up.family << endl;
			if (update.national_id != "")
				fout2 << update.national_id << endl;
			else
				fout2 << up.national_id << endl;
			if (update.employ_year != 0)
				fout2 << update.employ_year << endl;
			else
				fout2 << up.employ_year << endl;
			if (update.group_name != "")
				fout2 << update.group_name << endl;
			else
				fout2 << up.group_name << endl;
			if (update.degree != "")
				fout2 << update.degree << endl;
			else
				fout2 << up.degree << endl;
			if (update.academic_rank != "")
				fout2 << update.academic_rank << endl;
			else
				fout2 << up.academic_rank << endl;
			if (update.salary != 0)
				fout2 << update.salary << endl;
			else
				fout2 << up.salary << endl;
		}
		else
		{
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.employ_year << endl;
			fout2 << up.group_name << endl;
			fout2 << up.degree << endl;
			fout2 << up.academic_rank << endl;
			fout2 << up.salary << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempProf.txt");
	fout.open("Professor Information.txt");
	while (fin2 >> up.id
		   >> up.name
		   >> up.family
		   >> up.national_id
		   >> up.employ_year
		   >> up.group_name
		   >> up.degree
		   >> up.academic_rank
		   >> up.salary)
	{
		fout << up.id << endl;
		fout << up.name << endl;
		fout << up.family << endl;
		fout << up.national_id << endl;
		fout << up.employ_year << endl;
		fout << up.group_name << endl;
		fout << up.degree << endl;
		fout << up.academic_rank << endl;
		fout << up.salary << endl;
	}
	return upd;
}
bool update_emp_adv(employee update)
{
	bool upd = false;
	employee up;
	ofstream fout;
	ofstream fout2;
	ifstream fin;
	ifstream fin2;
	fin.open("Employee Information.txt");
	fout2.open("TempEmpl.txt");
	while (fin >> up.id >> up.name >> up.family >> up.national_id >> up.employ_year >> up.group_name >> up.salary)
	{
		if (up.id == update.id)
		{
			upd = true;
			fout2 << up.id << endl;
			if (update.name != "")
				fout2 << update.name << endl;
			else
				fout2 << up.name << endl;
			if (update.family != "")
				fout2 << update.family << endl;
			else
				fout2 << up.family << endl;
			if (update.national_id != "")
				fout2 << update.national_id << endl;
			else
				fout2 << up.national_id << endl;
			if (update.employ_year != 0)
				fout2 << update.employ_year << endl;
			else
				fout2 << up.employ_year << endl;
			if (update.group_name != "")
				fout2 << update.group_name << endl;
			else
				fout2 << up.group_name << endl;
			if (update.salary != 0)
				fout2 << update.salary << endl;
			else
				fout2 << up.salary << endl;
		}
		else
		{
			fout2 << up.id << endl;
			fout2 << up.name << endl;
			fout2 << up.family << endl;
			fout2 << up.national_id << endl;
			fout2 << up.employ_year << endl;
			fout2 << up.group_name << endl;
			fout2 << up.salary << endl;
		}
	}
	fin.close();
	fout2.close();
	fin2.open("TempEmpl.txt");
	fout.open("Employee Information.txt");
	while (fin2 >> up.id
		   >> up.name
		   >> up.family
		   >> up.national_id
		   >> up.employ_year
		   >> up.group_name
		   >> up.salary)
	{
		fout << up.id << endl;
		fout << up.name << endl;
		fout << up.family << endl;
		fout << up.national_id << endl;
		fout << up.employ_year << endl;
		fout << up.group_name << endl;
		fout << up.salary << endl;
	}
	return upd;
}

student* select_std_adv(student insert)
{
	student temp;
	student* select;
	bool equal[9];
	int equalNum;
	int selectNum = 0;
	int j = 0;
	bool existStd = false;
	ifstream fin;
	ifstream fin2;
	ofstream fout;
	fin.open("Students Information.txt");
	fout.open("Temp Select.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.entrance_year >> temp.math_grade >> temp.physics_grade >> temp.literature_grade >> temp.c_grade)
	{
		equalNum = 0;
		for (int i = 0; i < 9; i++)
		{
			equal[i] = false;
		}
		if (insert.id != 0)
		{
			if (insert.id == temp.id)
			{
				equal[0] = true;
			}
		}
		else
			equal[0] = true;
		if (insert.name != "")
		{
			if (insert.name == temp.name)
			{
				equal[1] = true;
			}
		}
		else
			equal[1] = true;
		if (insert.family != "")
		{
			if (insert.family == temp.family)
			{
				equal[2] = true;
			}
		}
		else
			equal[2] = true;
		if (insert.national_id != "")
		{
			if (insert.national_id == temp.national_id)
			{
				equal[3] = true;
			}
		}
		else
			equal[3] = true;
		if (insert.entrance_year != 0)
		{
			if (insert.entrance_year == temp.entrance_year)
			{
				equal[4] = true;
			}
		}
		else
			equal[4] = true;
		if (insert.math_grade != 0)
		{
			if (insert.math_grade == temp.math_grade)
			{
				equal[5] = true;
			}
		}
		else
			equal[5] = true;
		if (insert.physics_grade != 0)
		{
			if (insert.physics_grade == temp.physics_grade)
			{
				equal[6] = true;
			}
		}
		else
			equal[6] = true;
		if (insert.literature_grade != 0)
		{
			if (insert.literature_grade == temp.literature_grade)
			{
				equal[7] = true;
			}
		}
		else
			equal[7] = true;
		if (insert.c_grade != 0)
		{
			if (insert.c_grade == temp.c_grade)
			{
				equal[8] = true;
			}
		}
		else
			equal[8] = true;

		for (int k = 0; k < 9; k++)
		{
			if (equal[k] == true)
				equalNum++;
		}
		if (equalNum == 9)
		{
			selectNum++;
			fout << temp.id << endl;
			fout << temp.name << endl;
			fout << temp.family << endl;
			fout << temp.national_id << endl;
			fout << temp.entrance_year << endl;
			fout << temp.math_grade << endl;
			fout << temp.physics_grade << endl;
			fout << temp.literature_grade << endl;
			fout << temp.c_grade << endl;
		}
	}
	fin2.open("Temp Select.txt");
	if(selectNum == 0)
	{
       select = new student;
       return select;
    }
    else
	    select = new student[selectNum];
	while (fin2 >> select[j].id >> select[j].name >> select[j].family >> select[j].national_id >> select[j].entrance_year >> select[j].math_grade >> select[j].physics_grade >> select[j].literature_grade >> select[j].c_grade)
	{
		if (select[j].name == "----")
			select[j].name = "";
		if (select[j].family == "----")
			select[j].family = "";
		if (select[j].national_id == "----")
			select[j].national_id = "";
		j++;
		if (j >= selectNum)
			break;
	}
	return select;
}
professor* select_prof_adv(professor insert)
{
	professor temp;
	professor* select;
	bool equal[9];
	int equalNum;
	int selectNum = 0;
	int j = 0;
	bool existProf = false;
	ifstream fin;
	ifstream fin2;
	ofstream fout;
	fin.open("Professor Information.txt");
	fout.open("Temp Select.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.degree >> temp.academic_rank >> temp.salary)
	{
		equalNum = 0;
		for (int i = 0; i < 9; i++)
		{
			equal[i] = false;
		}
		if (insert.id != 0)
		{
			if (insert.id == temp.id)
			{
				equal[0] = true;
			}
		}
		else
			equal[0] = true;
		if (insert.name != "")
		{
			if (insert.name == temp.name)
			{
				equal[1] = true;
			}
		}
		else
			equal[1] = true;
		if (insert.family != "")
		{
			if (insert.family == temp.family)
			{
				equal[2] = true;
			}
		}
		else
			equal[2] = true;
		if (insert.national_id != "")
		{
			if (insert.national_id == temp.national_id)
			{
				equal[3] = true;
			}
		}
		else
			equal[3] = true;
		if (insert.employ_year != 0)
		{
			if (insert.employ_year == temp.employ_year)
			{
				equal[4] = true;
			}
		}
		else
			equal[4] = true;
		if (insert.group_name != "")
		{
			if (insert.group_name == temp.group_name)
			{
				equal[5] = true;
			}
		}
		else
			equal[5] = true;
		if (insert.degree != "")
		{
			if (insert.degree == temp.degree)
			{
				equal[6] = true;
			}
		}
		else
			equal[6] = true;
		if (insert.academic_rank != "")
		{
			if (insert.academic_rank == temp.academic_rank)
			{
				equal[7] = true;
			}
		}
		else
			equal[7] = true;
		if (insert.salary != 0)
		{
			if (insert.salary == temp.salary)
			{
				equal[8] = true;
			}
		}
		else
			equal[8] = true;

		for (int k = 0; k < 9; k++)
		{
			if (equal[k] == true)
				equalNum++;
		}
		if (equalNum == 9)
		{
			selectNum++;
			fout << temp.id << endl;
			fout << temp.name << endl;
			fout << temp.family << endl;
			fout << temp.national_id << endl;
			fout << temp.employ_year << endl;
			fout << temp.group_name << endl;
			fout << temp.degree << endl;
			fout << temp.academic_rank << endl;
			fout << temp.salary << endl;
		}
	}
	fin2.open("Temp Select.txt");
	if(selectNum == 0)
	{
       select = new professor;
       return select;
    }
    else
        select = new professor[selectNum];
	while (fin2 >> select[j].id >> select[j].name >> select[j].family >> select[j].national_id >> select[j].employ_year >> select[j].group_name >> select[j].degree >> select[j].academic_rank >> select[j].salary)
	{
		if (select[j].name == "----")
			select[j].name = "";
		if (select[j].family == "----")
			select[j].family = "";
		if (select[j].national_id == "----")
			select[j].national_id = "";
		if (select[j].group_name == "----")
			select[j].group_name = "";
		if (select[j].degree == "----")
			select[j].degree = "";
		if (select[j].academic_rank == "----")
			select[j].academic_rank = "";
		j++;
	}
	return select;
}
employee* select_emp_adv(employee insert)
{
	employee temp;
	employee* select;
	bool equal[7];
	int equalNum;
	int selectNum = 0;
	int j = 0;
	bool existEmpl = false;
	ifstream fin;
	ifstream fin2;
	ofstream fout;
	fin.open("Employee Information.txt");
	fout.open("Temp Select.txt");
	while (fin >> temp.id >> temp.name >> temp.family >> temp.national_id >> temp.employ_year >> temp.group_name >> temp.salary)
	{
		equalNum = 0;
		for (int i = 0; i < 7; i++)
		{
			equal[i] = false;
		}
		if (insert.id != 0)
		{
			if (insert.id == temp.id)
			{
				equal[0] = true;
			}
		}
		else
			equal[0] = true;
		if (insert.name != "")
		{
			if (insert.name == temp.name)
			{
				equal[1] = true;
			}
		}
		else
			equal[1] = true;
		if (insert.family != "")
		{
			if (insert.family == temp.family)
			{
				equal[2] = true;
			}
		}
		else
			equal[2] = true;
		if (insert.national_id != "")
		{
			if (insert.national_id == temp.national_id)
			{
				equal[3] = true;
			}
		}
		else
			equal[3] = true;
		if (insert.employ_year != 0)
		{
			if (insert.employ_year == temp.employ_year)
			{
				equal[4] = true;
			}
		}
		else
			equal[4] = true;
		if (insert.group_name != "")
		{
			if (insert.group_name == temp.group_name)
			{
				equal[5] = true;
			}
		}
		else
			equal[5] = true;
		if (insert.salary != 0)
		{
			if (insert.salary == temp.salary)
			{
				equal[6] = true;
			}
		}
		else
			equal[6] = true;

		for (int k = 0; k < 9; k++)
		{
			if (equal[k] == true)
				equalNum++;
		}
		if (equalNum == 7)
		{
			selectNum++;
			fout << temp.id << endl;
			fout << temp.name << endl;
			fout << temp.family << endl;
			fout << temp.national_id << endl;
			fout << temp.employ_year << endl;
			fout << temp.group_name << endl;
			fout << temp.salary << endl;
		}
	}
	fin2.open("Temp Select.txt");
	if(selectNum == 0)
	{
       select = new employee;
       return select;
    }
    else
	    select = new employee[selectNum];
	while (fin2 >> select[j].id >> select[j].name >> select[j].family >> select[j].national_id >> select[j].employ_year >> select[j].group_name >> select[j].salary)
	{
		if (select[j].name == "----")
			select[j].name = "";
		if (select[j].family == "----")
			select[j].family = "";
		if (select[j].national_id == "----")
			select[j].national_id = "";
		if (select[j].group_name == "----")
			select[j].group_name = "";

		j++;
	}
	return select;
}





