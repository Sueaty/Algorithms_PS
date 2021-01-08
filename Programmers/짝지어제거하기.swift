import Foundation

func solution(_ s: String) -> Int{
    var stack = [String]()
    s.map{ String($0) }.forEach {
        if stack.isEmpty {
            stack.append($0)
        } else {
            if let lastLetter = stack.last,
               lastLetter == $0 {
                   stack.removeLast()
            } else {
               stack.append($0)
            }
        }
    }
    
    return stack.isEmpty ? 1 : 0
}
