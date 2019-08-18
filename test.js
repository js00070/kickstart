process.stdin.resume();
process.stdin.setEncoding('utf-8');
// process.stdout.write('请输入:'); //标准输出
let caseNum=0;
let cases=[];
process.stdin.on('data', function first(data) {
    if(caseNum===0){
        caseNum=data;
        process.stdin.on('data', getInput);
    }
});

function getInput(data){
    cases.push(data);
   //console.log('input:',data)
    if(cases.length==caseNum*2){
        compute();
    }
}

function compute(){
    for(let i=0;i<caseNum;i++){
        let firstLine=cases[i*2];
        let secondLine=cases[i*2+1];
        let N=firstLine.split(' ')[0];
        let P=firstLine.split(' ')[1];
        let scores=secondLine.split(' ');
        scores.sort((a,b) => a-b);
        let scoresSort=[];
        let scoresNum=[];
        let hours=[];
        for(let j=0;j<N;j++){
            if(scores[j].indexOf('\r\n')!==-1){
                scores[j]=scores[j].split('\r\n')[0]
            }
            let index=scoresSort.indexOf(scores[j]);
            if(index==-1){
                scoresSort.push(scores[j]);
                scoresNum.push(1);
            }else{
                scoresNum[index]+=1;
            }
        }
        // console.log(scoresSort)
        // console.log(scoresNum)
        let countNum=0;
        let min=null;
        for(let k=0;k<scoresSort.length;k++){
            countNum+=scoresNum[k];
            if(countNum<P){
                hours.push(null);
            }else{
                let LackNum=P-scoresNum[k];
                if(LackNum<=0){
                    hours.push(0)
                    min=0;
                }else{
                    let hour=0;
                    while(LackNum>0){
                        for(let m=k-1;m>-1;m--){
                            if(scoresNum[m]>LackNum){
                                hour+=(scoresSort[k]-scoresSort[m])*LackNum;
                                LackNum=0;
                            }else{
                                hour+=(scoresSort[k]-scoresSort[m])*scoresNum[m];
                                LackNum-=scoresNum[m]
                            }
                        }
                    }
                    hours.push(hour);
                    if(min==null||hour<min){
                        min=hour;
                    }
                }
            }
            
        }
        console.log(min);
    }
}

// process.stdin.on('end', function () {
//      process.stdin.pause();
// });