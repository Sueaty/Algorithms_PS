
func solution(_ s: String) -> String {
    var answer = ""
    let arr = s.map { String($0) }
    if arr.count % 2 == 0 {
        answer.append(arr[arr.count/2 - 1])
        answer.append(arr[arr.count/2])
    } else {
        answer = arr[arr.count/2]
    }
    
    return answer
}
