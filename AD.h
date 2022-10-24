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
	if(true) // 음주가 가능한 유저라면 광고를 노출시킨다.
	{
		cout << "맥주 광고가 노출됩니다.\n";
	}
	else // 음주 가능 여부는 DrinkableUser()에서 처리한다, 하지만 맥주를 마실 수 있는 조건이 다른 국가가 추가되면 else if 문을 추가해 줘야 한다.
	{
		cout << "맥주 광고가 차단됩니다.\n";
	}
}

inline bool AD::DrinkableUser(User user)
{
	// 유저의 나이와 국가정보를 받아온뒤 음주가 가능한지 여부를 판단한다.
	if(user.Age >=20 && user.country == "Korea")
	{
		return true;
	} 
	else
	{
		return false;
	}
	// 여기서 문제점은 국가마다 나이계산법이나 음주가능한 나이가 다르다는 점이다. 음주가 가능한 새로운 조건이 나온다면 다른 함수를 추가해줘야 한다.
	// DrinkableUser_america, DrinkableUser_japan 등등
}



// 위와 같은 상황에서 유용한 방법이 델리게이트이다.
// 1. 국가별 음주가능 여부에 대한 함수를 만들고 델리게이트에 저장한다.
// 2. ShowBeerAD 함수에 1에서 만든 함수를 파라미터 값으로 받는다.

// c++에는 delegate가 없다. 하지만 언리얼엔진에서 프레임워크를 자체제작하여 사용하고 있다.
