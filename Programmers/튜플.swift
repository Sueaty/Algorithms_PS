import Foundation

func solution(_ s:String) -> [Int] {
    // 앞 뒤 잘라서 {2},{2,1},{2,1,3},{2,1,3,4} 를 먼저 만들고
    let fIndex = s.startIndex
    let lIndex = s.endIndex
    let str = s[s.index(fIndex, offsetBy: 1)..<s.index(lIndex, offsetBy: -2)]

    // ["2", "2,1", "1,2,3", "1,2,4,3"] 형태로 만듬
    var arr = str.components(separatedBy: "},")
    arr = arr.map { sets in
        let fIndex = sets.startIndex
        return String(sets[sets.index(fIndex, offsetBy: 1)...])
    }
    arr.sort { $0.count < $1.count }

    var answer = [Int]()
    arr.forEach { set in
        let array = set.components(separatedBy: ",").map{ Int($0)! }
        for num in array {
            if !answer.contains(num) {
                answer.append(num)
                break
            }
        }
    }
    
    return answer
}
