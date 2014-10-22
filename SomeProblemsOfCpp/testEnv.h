#include <iostream>


using namespace std;


class Env
{
public:
	Env()
	{}
	virtual ~Env()
	{}
	virtual void read() = 0;
};


class EnvWrapper :public Env
{
public:
	EnvWrapper(Env *t) :_target(t)
	{}
	virtual ~EnvWrapper()
	{}
	void read()
	{
		cout << "wrapperEnv" << endl;
		return _target->read();
	}
private:
	Env * _target;
};


class InMemoryEnv :public EnvWrapper
{
public:
	InMemoryEnv(Env *baseEnv) :EnvWrapper(baseEnv)
	{}
	virtual ~InMemoryEnv()
	{}
	virtual void read()
	{
		cout << "InMemoryEnv read()" << endl;
	}
};


class PosixEnv :public Env
{
public:
	PosixEnv(){}
	virtual ~PosixEnv(){}
	void read()
	{
		cout << "PosixEnv read()" << endl;
	}
};


void testEnv()
{
	Env *env = new InMemoryEnv(new PosixEnv);
	env->read();
}