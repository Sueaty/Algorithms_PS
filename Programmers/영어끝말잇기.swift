import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var set = Set<String>()
    set.insert(words[0])

    for idx in 1..<words.count {
        // check rule 1
        let previous = words[idx - 1]
        let current = words[idx]
        if previous[previous.index(previous.endIndex, offsetBy: -1)] != current[current.startIndex] {
            break
        }

        // check rule 2
        set.insert(words[idx])
        if set.count != (idx + 1) {
            break
        }
    }

    var answer = [Int]()
    if words.count == set.count {
        answer = [0, 0]
    } else {
        let a = set.count % n + 1
        let b = set.count / n + 1
        answer = [a, b]
    }
    
    return answer
}
