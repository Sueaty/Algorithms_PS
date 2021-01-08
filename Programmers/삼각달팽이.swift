import Foundation

func solution(_ n: Int) -> [Int] {
    var arr = Array(repeating: Array(repeating: 0, count: n), count: n)
    var fillFor = n
    var fill = 0
    var x = -1
    var y = 0
    
    if n == 1 { return [1] }
    if n == 2 { return [1, 2, 3] }
    
    let pair = n / 3
    let extra = n % 3

    for _ in 0..<pair {
        for _ in 0..<fillFor {
            x += 1
            fill += 1
            arr[x][y] = fill
        }
        fillFor -= 1

        for _ in 0..<fillFor {
            y += 1
            fill += 1
            arr[x][y] = fill
        }
        fillFor -= 1
        
        for _ in 0..<fillFor {
            x -= 1
            y -= 1
            fill += 1
            arr[x][y] = fill
        }
        fillFor -= 1
    }
    
    if extra == 1 {
        for _ in 0..<fillFor {
            x += 1
            fill += 1
            arr[x][y] = fill
        }
    } else if extra == 2 {
        for _ in 0..<fillFor {
            x += 1
            fill += 1
            arr[x][y] = fill
        }
        fillFor -= 1

        for _ in 0..<fillFor {
            y += 1
            fill += 1
            arr[x][y] = fill
        }
    }

    var answer = [Int]()
    for i in 0..<n {
        answer.append(contentsOf: arr[i].filter{ $0 != 0 })
    }
    return answer
}
