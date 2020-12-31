
func solution(_ s: String) -> Bool {
    var answer = false
    if s.count == 4 || s.count == 6 {
        let letter = Array("abcdefghijklmnopqrstuvwxyz")
        answer = !s.contains(where: letter.contains)
    }
    return answer
}
