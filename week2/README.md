### connect_led

- delay 간격으로 3개의 led를 껐다 켰다 한다.
- 기본적으로 저항, led 의 적절한 활용에 대해 배울 수 이었다.

### red_infra_sensor

- 적외선 센서의 결과 값을 digital로 받아서 그 결과를 led로 보여주는 간단한 회로

### switch_pull_down

- 스위치 작동
- Pull Down 저항을 넣어줘야 swich open 상태일 때 floating 상태가 됨으로써 발생하는 예상치 못한 동작을 예방할 수 있음을 배웠다.
  - pull down, up은 이제 딱 보면 알고 쓸 수는 있는데 뭔가 근본적으로 약간 찜찜한 부분이 남은 느낌. 예전에 공부했던 전기전자회로 코스를 다시 봐야겠다.

### potentiometer

> 포텐시오미터란? vcc, gnd 를 연결하고 out으로 Analog Value를 전달한다. Analog Value는 기체에 달려 있는 회전 와이퍼를 통해 0-1023, 1024개 value가 조절된다.

- 별개 없고, 그냥 Analog Input을 가져와서 그걸 Serial Monitor에서 볼 수 있도록 Print 하는 정도 코드이다.
