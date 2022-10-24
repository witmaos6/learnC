#include <iostream>
#include "AD.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}

// 델리게이트란? 오브젝트 상의 멤버 함수를 가리키고 실행시키는 데이터 유형이다.
// 쉽게 말해 함수를 저장하는 변수이고 다음과 같은 특징을 가지고 있다.
// 1. 함수 포인터의 직접 접근이 아닌 대리자를 통한 함수 호출 방식 
// 2. 호출할 함수나 이를 포함하는 객체가 없어져도 대리자가 체크해 안전하게 처리할 수 있음.
// 3. 동일한 형을 가진 함수 여러 개를 대리자가 묶어서 관리하고, 필요할 때 동시에 모두 호출하는 것이 가능함.

// 3번의 기능은 플레이어가 죽었을 때 모든 컨트롤 기능을 해제시키거나 보스몬스터가 죽었을 때 보스몬스터가 소환한 잡몹들도 연쇄적으로 죽이는 등의 기능을 구현할 때 사용될 것 같다.

//델리게이트 오브젝트는 복사해도 완벽히 안전합니다.
//델리게이트는 값으로 전달 가능하나 보통 추천할 만 하지는 않는데, heap 에 메모리를 할당해야 하기 때문입니다.
//가급적이면 델리게이트는 항상 참조 전달해야 합니다. -https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/