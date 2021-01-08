import Foundation

func solution(_ brown: Int, _ yellow: Int) -> [Int] {
    var x = 0
    var y = 0
    for i in stride(from: Int(sqrt(Double(yellow))), to: 0, by: -1) {
        x += 1
        if yellow % x == 0 {
            y = yellow / x
            if (x + 2) * (y + 2) - yellow == brown { break }
        }
    }
    return [y + 2, x + 2]
}
