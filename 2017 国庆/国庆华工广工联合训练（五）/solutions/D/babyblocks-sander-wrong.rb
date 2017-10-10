# very slow solution, to check other impl.
$stdin.gets.to_i.times{
  target = gets.strip
  perms = target.split('').permutation.to_a.sort.map{|c| c.join }
  puts perms.index(target)
}
