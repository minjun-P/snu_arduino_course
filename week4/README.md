### header, cpp 나누기

- header 파일과 cpp를 나눠서 사용하는 방법에 대해 다룸.
- `#include <Arduino.h>` 이걸 h파일에 추가해주는 것을 추천한다고 한다. 그래야 다른 ide에서 해도 별 문제 없이 안 터진다는 듯.

### 모터 컨트롤

- pin마다 maximum current 제약이 있다.
- ecu(engine control unit)이 중요하다는 잡담.
  - 이런 느낌의 mcu가 생긴 뒤로 차체에 들어가는 전선이 베리 가벼워졌다고 함. 간단해지고

### 릴레이

- 마이크로 컨트롤러를 사용하여 큰 전기르르 컨트롤 할 때 사용된다.
- NO(Normal Open), NC(Normal Close)라는 개념이 있음

### interrupt

- 의도적으로 delay를 줘서, 풀다운 led 회로에서 스위치에 대한 반응성을 느리게 만들었음.
- 이제 interrupt 플젝에서, attchIntterupt를 2번 핀에 listen해서, change 시마다 loop의 delay를 무시하고 값을 박아버리는 연습을 해보았음.
- 내부적으로 PC(PROGRAM COUNTER)를 사용하는데, interrupt 한 뒤에, 너무 많은 작업을 하면 pc 점프 범위를 초과해서, 다시 원래대로 돌아갈 수가 없게 되는 상황이...
