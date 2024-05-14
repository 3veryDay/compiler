/*
재귀 호출을 이용한 factorial 계산 프로그램
*/

void main()
{
  int n, f;
  read(n);
  write(n);
  f = factorial(n);
  write(f);
}
int factorial(int n)
{
  if (n == 1) return 1;
  else return n*factorial(n-1);
}
