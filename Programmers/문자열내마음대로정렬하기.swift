
func solution(_ strings: [String], _ n: Int) -> [String] {
    return strings.sorted {
        let first = $0[$0.index($0.startIndex, offsetBy: n)]
        let second = $1[$1.index($1.startIndex, offsetBy: n)]
        
        if first == second {
            return $0 < $1
        } else {
            return first < second
        }
    }
}
