func solution(_ clothes: [[String]]) -> Int {
    var info: [String: Int] = [:]
    
    clothes.forEach{ c in
        if let value = info[c[1]] {
            info.updateValue(value + 1, forKey: c[1])
        } else {
            info.updateValue(2, forKey: c[1])
        }
    }
    
    let answer = [Int](info.values).reduce(1, *) - 1
    return answer
}
