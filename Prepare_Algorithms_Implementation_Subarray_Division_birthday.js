function birthday(s, d, m) {
    let cnt = 0;
    for(let i=0; i<=s.length - m; i++){
        let sum = 0;
        for(let j = 0; j<m; j++){
            sum += s[j+i];
        }
        if(sum === d){
            cnt++;
        }
    }
    return cnt;    
}
