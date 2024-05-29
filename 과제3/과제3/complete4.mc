int score(int a, int b, int c, int d){
	int score = 100;
	
	if(a==1){
		score++;
	}
	if(b ==2){
		score--;
	}
	if(c == 3){
		score=score*2;
	}
	if(d ==4){
		score=score/2;
	}
	return score;
}
