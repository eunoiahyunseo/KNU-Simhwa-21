import React from "react";
import styled from "styled-components";
import qs from "qs";
import Button from "../common/Button";
import palette from "../../lib/styles/palette";

const PaginationBlock = styled.div`
  margin: 10px 40px;
  padding: 30px 10px;
  display: flex;
  justify-content: space-between;
  margin-bottom: 3rem;
  border-top: 1px solid ${palette.gray[2]};

  a {
    text-decoration: none;
  }
`;

const buildLink = ({ username, tag, page }) => {
  const query = qs.stringify({ tag, page });
  return username ? `/@${username}?${query}` : `/?${query}`;
};

const PageNumber = styled.div``;

const Pagination = ({ page, lastPage, username, tag }) => {
  return (
    <PaginationBlock>
      <Button
        disabled={page === 1}
        to={
          page === 1
            ? undefined
            : buildLink({ username, tag, page: page - 1 })
        }
      >
        이전
      </Button>
      <PageNumber>{page}</PageNumber>
      <Button
        disabled={page === lastPage}
        to={
          page === lastPage
            ? undefined
            : buildLink({ username, tag, page: page + 1 })
        }
      >
        다음
      </Button>
    </PaginationBlock>
  );
};

export default Pagination;
