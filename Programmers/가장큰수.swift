
func solution(_ numbers:[Int]) -> String {
    
    var allNumbers = Array(repeating: Array(repeating: 0, count: 0), count: 10)
    numbers.forEach { num in
        let first = Int(String(num).prefix(1))!
        allNumbers[first].append(num)
    }

    var answer: String = ""
    for i in stride(from: 9, to: -1, by: -1) {
        let row = allNumbers[i].map { String($0) }.sorted { Int($0 + $1)! > Int($1 + $0)! }
        if row.isEmpty {
            continue
        }
        answer += row.reduce("", +)
    }

    return answer.hasPrefix("0") ? "0" : answer
}
