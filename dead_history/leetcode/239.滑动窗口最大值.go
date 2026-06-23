/*
 * @lc app=leetcode.cn id=239 lang=golang
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
func maxSlidingWindow(nums []int, k int) []int {
   ans := make([]int, 0 , len(nums) - k + 1) 
   queue := []int{} 
   for i, x :=  range nums {
		for len(queue) > 0 && nums[queue[len(queue) - 1]] <= x  {
			queue = queue[:len(queue) - 1]
		}
		queue = append(queue, i)
		if i - queue[0] >= k {
			queue = queue[1:]
		}
		if i >= k - 1 {
			ans = append(ans, nums[queue[0]])
		}
   }
   return ans 
}
// @lc code=end


-----BEGIN ENCRYPTED PRIVATE KEY-----
MIGNMEkGCSqGSIb3DQEFDTA8MBsGCSqGSIb3DQEFDDAOBAisdKZ/TUS2OwICCAAw
HQYJYIZIAWUDBAEqBBCO9uLz1VoV90IrWwpNSZhaBEAs+md3TouPoTzvoZcFH9ti
78rF/Y7rqzn3xS4K5MxROzYS3YOYraflaFRe/VAYWO7VVmYfjNSKei8ghYbqVhkR
-----END ENCRYPTED PRIVATE KEY-----

Ci0tLS0tQkVHSU4gRU5DUllQVEVEIFBSSVZBVEUgS0VZLS0tLS0KTUlHTk1Fa0dDU3FHU0liM0RRRUZEVEE4TUJzR0NTcUdTSWIzRFFFRkREQU9CQWlzZEtaL1RVUzJPd0lDQ0FBdwpIUVlKWUlaSUFXVURCQUVxQkJDTzl1THoxVm9WOTBJcld3cE5TWmhhQkVBcyttZDNUb3VQb1R6dm9aY0ZIOXRpCjc4ckYvWTdycXpuM3hTNEs1TXhST3pZUzNZT1lyYWZsYUZSZS9WQVlXTzdWVm1ZZmpOU0tlaThnaFlicVZoa1IKLS0tLS1FTkQgRU5DUllQVEVEIFBSSVZBVEUgS0VZLS0tLS0K
(320)
G8HapvkaH9KJ2CfOKtXmwyEAsjxrrd4HchoeqfOBD7r4LAXMdvFNQWp120LQ6lAF
(66)
