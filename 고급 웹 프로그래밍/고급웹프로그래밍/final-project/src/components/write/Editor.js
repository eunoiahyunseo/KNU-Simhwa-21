import React, { useEffect, useRef, useMemo } from "react";
import ReactQuill, { Quill } from "react-quill";
import ImageResize from "quill-image-resize-module-react";
import "react-quill/dist/quill.snow.css";
import styled from "styled-components";
import palette from "../../lib/styles/palette";
import Responsive from "../common/Responsive";
import axios from "axios";
import imageCompression from "browser-image-compression";

Quill.register("modules/imageResize", ImageResize);

const EditorBlock = styled(Responsive)`
  padding-top: 5rem;
`;

const TitleInput = styled.input`
  font-size: 2rem;
  outline: none;
  padding-bottom: 0.5rem;
  width: 100%;
  border: none;
  border-bottom: 1px solid ${palette.gray[4]};
  margin-bottom: 2rem;
`;

const QuillWrapper = styled.div`
  .ql-container {
    border-radius: 0px 0px 10px 10px;
  }

  .ql-editor {
    padding: 0px;
    min-height: 320px;
    font-size: 1.125rem;
    line-height: 1.5;
  }

  .ql-editor.ql-blank:before {
    left: 0px;
  }
`;

// 이미지를 저장할 input요소를 만들어야 한다.
// 에디터에서 이미지 버튼을 클릭 시, 만든 input요소가 클릭되게 한다.
// 클릭된 input요소에 이미지를 넣는다 = change이벤트 발생

const EditorContent = ({ placeholder, body, onChangeField }) => {
  const quillElement = useRef(null);
  const quillInstance = useRef();

  const toolbarOptions = [
    ["link", "image", "video"],
    [{ header: [1, 2, 3, false] }],
    ["bold", "italic", "underline", "strike"],
    ["blockquote"],
    [{ list: "ordered" }, { list: "bullet" }],
    [{ color: [] }, { background: [] }],
    [{ align: [] }],
  ];

  // 옵션에 상응하는 포맷, 추가해주지 않으면 text editor에 적용된 스타일을 볼수 없음
  const formats = [
    "header",
    "font",
    "size",
    "bold",
    "italic",
    "underline",
    "strike",
    "align",
    "blockquote",
    "list",
    "bullet",
    "indent",
    "background",
    "color",
    "link",
    "image",
    "video",
    "width",
  ];

  const imageHandler = () => {
    const input = document.createElement("input");
    input.setAttribute("type", "file");
    input.setAttribute("accept", "image/*");
    input.click();
    input.addEventListener("change", async () => {
      if (input.files) {
        let file = input.files[0];
        const options = {
          maxSizeMB: 2,
          maxWidthOrHeight: 500,
        };
        try {
          const compressedFile = await imageCompression(
            file,
            options
          );
          file = compressedFile;

          // resize된 이미지의 url을 받아 fileUrl에 저장
          const promise =
            imageCompression.getDataUrlFromFile(compressedFile);
          promise.then((result) => {
            file = result;
          });
        } catch (error) {
          console.log(error);
        }

        const formData = new FormData();
        formData.append("image", file);
        const editor = quillInstance.current;
        const range = editor.getSelection(true);
        try {
          const result = await axios.post(
            `${process.env.REACT_APP_CLIENT_HOST}/api/upload`,
            formData
          );
          const IMG_URL = result.data.url;
          editor.root.innerHTML += `<img src=${IMG_URL}>`;
        } catch (error) {
          editor.deleteText(range.index, 1);
          return;
        }
      }
    });
  };

  // useMemo를 사용하지 않으면 매 렌더링 마다 modules가 다시 생성된다 => 커서를 찾지 못하므로 이렇게 하면 안됨
  const modules = useMemo(() => {
    return {
      toolbar: {
        container: toolbarOptions,
        handlers: {
          image: imageHandler,
        },
      },
      clipboard: {
        // toggle to add extra line breaks when pasting HTML:
        matchVisual: false,
      },
      imageResize: {
        parchment: Quill.import("parchment"),
        modules: ["Resize", "DisplaySize"],
      },
    };
  }, []);

  useEffect(() => {
    quillInstance.current = new Quill(quillElement.current, {
      theme: "snow",
      modules,
      placeholder,
      formats,
    });

    const quill = quillInstance.current;
    quill.on("text-change", (delta, oldDelta, source) => {
      if (source === "user") {
        onChangeField({
          key: "body",
          value: quill.root.innerHTML,
        });
      }
    });
    /* eslint-disable-next-line */
  }, [onChangeField]);

  // 마운트 될 떄 한번만
  useEffect(() => {
    quillInstance.current.root.innerHTML = body;
    /* eslint-disable-next-line */
  }, []);

  return <div ref={quillElement}></div>;
};

const CapacityContainer = styled.div`
  margin-top: 20px;
  display: flex;
  justify-content: flex-end;
  align-items: center;
`;
const Capacity = styled.input`
  margin-left: 10px;
  width: 100px;
`;

const Editor = ({ title, body, onChangeField, capacity }) => {
  const onChangeTitle = (e) => {
    const {
      target: { value },
    } = e;
    onChangeField({ key: "title", value });
  };

  const onChangeCapacity = (e) => {
    const {
      target: { value },
    } = e;
    onChangeField({ key: "capacity", value });
  };

  return (
    <EditorBlock>
      <TitleInput
        placeholder="스터디 제목"
        onChange={onChangeTitle}
        value={title}
      />

      <QuillWrapper>
        <EditorContent
          placeholder="스터디 모집 공고"
          onChangeField={onChangeField}
          body={body}
        />
      </QuillWrapper>
      <CapacityContainer>
        <span>스터디 모집 인원</span>
        <Capacity
          type="number"
          min="2"
          max="20"
          onChange={onChangeCapacity}
          value={capacity}
        />
      </CapacityContainer>
    </EditorBlock>
  );
};

export default Editor;
