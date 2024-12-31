# 알고리즘 전용 Repository

게을러지지않기 위해 만들었습니다.<br/>

### push 규칙

`add : [사이트이름]-[문제번호]`
`add : [새로 알게 된 것의 이름]`

### 사용할 언어들

```
- C
- javaScript
```

### 새로 알게 된 것들(C)

```
fgets
- 특징 : string을 받을 때 사용 (scanf("%s) 대체용)
- 기본 사용 방법 : fgets(받을 string변수, sizeof(받을 string변수), stdin);
- 주의 사항 : 입력받는 Enter값까지 받기 때문에 원래 길이의 +2, +3정도 해주는게 좋다
```

```
EOF 처리(End Of File)
- 특징 : 더 이상 읽을 데이터가 없는 경우에 사용
- 기본 사용 방법 : scanf("%d",&n); 일때 scanf("%d",&n) != -1 로 사용 가능하다.(EOF = -1)
- 주의 사항 : 주의사항은 따로 없는거같은데 백준 칸토어 집합과 같은 사항에서 쓰인다.
```
