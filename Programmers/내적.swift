
func solution(_ a:[Int], _ b:[Int]) -> Int {
    var answer = 0
    a.enumerated().forEach { (index, element) in
       answer += (element * b[index])         
    }
    return answer
}
