/* 
펠린드롬 수: 자릿수를 뒤집어도 변하지 않는 수 
121, 1221 과 같은 수는 펠린드롬에 해당한다. 
*/

void main{} {
int org, rev; // org: original, rev: reverse
int i, j;

read(org);
if (org <0) {
  org = (-1) * org;
  }
i = org;
rev = 0;
while (i != 0) {
  j = i % 10;
  rev = rev * 10 + j;
  i /= 10;
  }
if (rev == org) {
  write(org);
  }
}
