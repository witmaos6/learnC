#pragma once
using namespace std;

struct User
{
	int Age;
	string country;
};

class AD
{
public:
	void ShowBeerAD();

	bool DrinkableUser(User user);
};

inline void AD::ShowBeerAD()
{
	if(true) // ���ְ� ������ ������� ���� �����Ų��.
	{
		cout << "���� ���� ����˴ϴ�.\n";
	}
	else // ���� ���� ���δ� DrinkableUser()���� ó���Ѵ�, ������ ���ָ� ���� �� �ִ� ������ �ٸ� ������ �߰��Ǹ� else if ���� �߰��� ��� �Ѵ�.
	{
		cout << "���� ���� ���ܵ˴ϴ�.\n";
	}
}

inline bool AD::DrinkableUser(User user)
{
	// ������ ���̿� ���������� �޾ƿµ� ���ְ� �������� ���θ� �Ǵ��Ѵ�.
	if(user.Age >=20 && user.country == "Korea")
	{
		return true;
	} 
	else
	{
		return false;
	}
	// ���⼭ �������� �������� ���̰����̳� ���ְ����� ���̰� �ٸ��ٴ� ���̴�. ���ְ� ������ ���ο� ������ ���´ٸ� �ٸ� �Լ��� �߰������ �Ѵ�.
	// DrinkableUser_america, DrinkableUser_japan ���
}



// ���� ���� ��Ȳ���� ������ ����� ��������Ʈ�̴�.
// 1. ������ ���ְ��� ���ο� ���� �Լ��� ����� ��������Ʈ�� �����Ѵ�.
// 2. ShowBeerAD �Լ��� 1���� ���� �Լ��� �Ķ���� ������ �޴´�.

// c++���� delegate�� ����. ������ �𸮾������� �����ӿ�ũ�� ��ü�����Ͽ� ����ϰ� �ִ�.
