
func solution(_ a: Int, _ b: Int) -> Int64 {
    let arr = a < b ? Array(a...b) : Array(b...a)
    if arr.count == 1 {
        return Int64(arr[0])
    }
    
    let endSum = arr[0] + arr[arr.count-1]
    return Int64(endSum * arr.count / 2)
}
