
func solution(_ s:String) -> Bool
{
    let str = s.lowercased().sorted()
    var count = [0, 0]
    if str.contains("p") {
        if let i = str.firstIndex(of: "p"),
           let j = str.lastIndex(of: "p") {
               count[0] = j - i + 1
           }
    }
    if str.contains("y") {
        if let i = str.firstIndex(of: "y"),
           let j = str.lastIndex(of: "y") {
               count[1] = j - i + 1
           }
    }
    
    return count[0] == count[1]
}
