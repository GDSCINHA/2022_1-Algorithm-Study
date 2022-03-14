const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString();

let num = input;
const sticks = [64, 32, 16, 8, 4, 2, 1]
let cnt = 0

while (num != 0){
    for (let i = 0; i < sticks.length; i++){
        if (num - sticks[i] >= 0){
            num = num - sticks[i]
            cnt += 1
            
            delete sticks[i]
            break
        }  
    }
}

console.log(cnt)