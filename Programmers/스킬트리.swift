import Foundation

func solution(_ skill: String, _ skill_trees: [String]) -> Int {
    var answer = 0
    let skillArr = Array(skill)
    
    for tree in skill_trees {
        let arr = Array(tree) //[b, a, c, d, e]
        var str = ""
        arr.forEach { if skill.contains($0) { str += String($0) } }
        
        if str == skill { 
            answer += 1
        } else {
            let strArr = Array(str)
            var isRight = true
            for index in 0..<strArr.count {
                if strArr[index] != skillArr[index] { 
                    isRight = false 
                    break
                }
            }
            if isRight { answer += 1 }
        }
    }
    
    return answer
}
