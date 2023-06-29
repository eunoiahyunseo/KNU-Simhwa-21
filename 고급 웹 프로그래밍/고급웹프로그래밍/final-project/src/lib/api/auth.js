import client from "./client";

// 로그인
export const login = ({ email, password }) =>
  client.post("/api/auth/login", { email, password });

// 회원가입
export const register = ({ email, password }) =>
  client.post("/api/auth/register", { email, password });

// 로그인 상태 확인
export const check = () => client.get("/api/auth/check");

// 로그아웃
export const logout = () => client.post("/api/auth/logout");

// 회원정보 수정
export const editProfile = ({ _id, email, username }) =>
  client.patch(`/api/auth/${_id}`, { email, username });

export const check_like_user = (userInfo) =>
  client.post(`/api/auth/like_user`, userInfo);
