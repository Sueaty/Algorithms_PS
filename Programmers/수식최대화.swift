import Foundation

let operators = [["*", "+", "-"], ["*", "-", "+"],
                 ["+", "*", "-"], ["+", "-", "*"],
                 ["-", "+", "*"], ["-", "*", "+"]]

func solution(_ expression:String) -> Int64 {
    var exprArr = expression.components(separatedBy: CharacterSet(charactersIn: "*+-"))
    var pos = 1
    expression.map{ String($0) }.forEach { char in
        if char == "-" || char == "*" || char == "+" {
            exprArr.insert(char, at: pos)
            pos += 2
        }
    }

    var results = [Int64]()
    operators.forEach { order in
        var calc = exprArr
        let orderArr = order.map{ String($0) }.forEach { op in
            while calc.firstIndex(of: op) != nil {
                let index = calc.firstIndex(of: op)!
                if op == "*" {
                    calc[index - 1] = String(Int(calc[index - 1])! * Int(calc[index + 1])!)
                } else if op == "+" {
                    calc[index - 1] = String(Int(calc[index - 1])! + Int(calc[index + 1])!)
                } else {
                    calc[index - 1] = String(Int(calc[index - 1])! - Int(calc[index + 1])!)
                }
                calc.remove(at: index + 1)
                calc.remove(at: index)
            }
        }
        if calc[0].hasPrefix("-") {
            results.append(Int64(calc[0])! * -1)
        } else {
            results.append(Int64(calc[0])!)
        }
    }
    
    return results.max()!
}
