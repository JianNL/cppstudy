#ifndef TESTCEREAL_H
#define TESTCEREAL_H
#include <iostream>
#include <map>
#include <memory>
#include <cereal/archives/binary.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/string.hpp>

using namespace std;


struct MyRecord
{
public:
	int x;
	int y;
	float z;
	template <class Archive>
	void Serialize(Archive &ar,const unsigned int version)
	{
		ar(x, y);
		ar(z);
	}

	friend ostream& operator<<(ostream &os, const MyRecord &mr);
};


ostream& operator<<(ostream &os, const MyRecord &mr)
{
	os << "MyRecord(" << mr.x << "," << mr.y << "," << mr.z << ")" << endl;
	return os;
}

class SomeData
{
public:
	SomeData(int i = 0) :id(i), data(new std::unordered_map<int,MyRecord>)
	{}

	int id;
	std::shared_ptr<std::unordered_map<int, MyRecord> > data;
	

	template <class Archive>
	void Serialize(Archive &ar,const unsigned int version)
	{
		ar(id, data);
	}
		

public:

	void push(int i, const MyRecord &mr)
	{
		data->insert(std::make_pair(i, mr));
	}


	void print()
	{
		std::cout << "id:" << id << endl;
		if (data->empty())
		{
			return;
		}
		for (auto &e:(*data))
		{
		}
	}

};


void test()
{
	{
		std::ofstream os("my.binary", std::ios::binary);
		cereal::BinaryOutputArchive archive(os);

		int age = 26;
		std::string name = "fd";
		archive(CEREAL_NVP(age), CEREAL_NVP(name));

		os.close();
	}


	{
		std::ifstream is("my.binary", std::ios::binary);
		cereal::BinaryInputArchive archive(is);
		int age;
		std::string name;
		archive(age, name);
		cout << age << " " << name << endl;
	}
}

void test1()
{
	{
		std::ofstream os("obj.cereal", std::ios::binary);
		cereal::BinaryOutputArchive archive(os);


		MyRecord mr = { 1, 2, 3.0 };
		SomeData myData(1111);
		myData.push(100, mr);
		archive(myData);
	}

	/*
	{
		std::ifstream is("ojb.cereal", std::ios::binary);
		cereal::BinaryInputArchive archive(is);


		SomeData myData;
		archive(myData);
		myData.print();
	}
	*/
}


#endif